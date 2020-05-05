// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapRotatorComponent.h"
#include "GameFramework/Actor.h"
#include "Containers/StaticArray.h"

// Sets default values for this component's properties
UGameMapRotatorComponent::UGameMapRotatorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called every frame
void UGameMapRotatorComponent::TickComponent(float DeltaTime, ELevelTick TickType, 
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (this->bCanRotate_)
	{
		this->Rotate(DeltaTime);
	}
}

void UGameMapRotatorComponent::StartRotating()
{
	if (this->bRotating_) return;

	this->Owner_ = GetOwner();

	this->RotationSpeed_ = RotationsSpeeds::GetRandom();
	this->UpdateTargetRotation();

	this->bCanRotate_ = true;
	this->bRotating_ = true;
}

void UGameMapRotatorComponent::StopRotating()
{
	if (!this->bRotating_) return;

	this->bCanRotate_ = false;
	this->bRotating_ = false;
}

bool UGameMapRotatorComponent::isRotating() const
{
	return this->bRotating_;
}

// Called when the game starts
void UGameMapRotatorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UGameMapRotatorComponent::Rotate(float DeltaTime)
{
	if (!this->bCanRotate_) return;

	if (this->Owner_ != nullptr)
	{
		const FQuat CurrentQuat = this->Owner_->GetActorQuat();

		const FQuat DeltaRotation = FMath::
			QInterpConstantTo(CurrentQuat, this->TargetRotation_, DeltaTime, this->RotationSpeed_);

		if (DeltaRotation.Equals(this->TargetRotation_))
		{
			this->UpdateTargetRotation();
		}

		this->Owner_->SetActorRotation(DeltaRotation);
	}
}

void UGameMapRotatorComponent::UpdateTargetRotation()
{
	if (this->Owner_ != nullptr)
	{
		const FQuat CurrentQuat = this->Owner_->GetActorQuat();
		const FQuat TargetQuat = FRotator(2.f, 0.f, 0.f).Quaternion();

		this->TargetRotation_ = TargetQuat * CurrentQuat;
	}
}