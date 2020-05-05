// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapMovementComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UGameMapMovementComponent::UGameMapMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called every frame
void UGameMapMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, 
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (this->bCanMove_)
	{
		this->Move(DeltaTime);
	}
}

void UGameMapMovementComponent::StartMoving()
{
	if (this->bMoving_) return;

	this->Owner_ = GetOwner();

	this->MovementSpeed_ = UGameMapMovementComponent::GetRandomMovementSpeed();
	this->UpdateTargetLocation();

	this->bCanMove_ = true;
	this->bMoving_ = true;
}

void UGameMapMovementComponent::StopMoving()
{
	if (!this->bMoving_) return;

	this->bCanMove_ = false;
	this->bMoving_ = false;
}

bool UGameMapMovementComponent::isMoving() const
{
	return this->bMoving_;
}

// Called when the game starts
void UGameMapMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}

EMovementSpeeds::Type UGameMapMovementComponent::GetRandomMovementSpeed()
{
	TArray<EMovementSpeeds::Type> Speeds
	{
		EMovementSpeeds::Normal,
		EMovementSpeeds::Medium,
		EMovementSpeeds::Quick
	};

	uint8 SpeedIndex = FMath::RandRange(0, Speeds.Num() - 1);

	return Speeds[SpeedIndex];
}

void UGameMapMovementComponent::Move(float DeltaTime)
{
	if (!this->bCanMove_) return;

	if (this->Owner_ != nullptr)
	{
		const FVector CurrentLocation = this->Owner_->GetActorLocation();

		const FVector DeltaLocation = FMath::
			VInterpConstantTo(CurrentLocation, this->TargetLocation_, DeltaTime, this->MovementSpeed_);

		if (DeltaLocation.Equals(this->TargetLocation_))
		{
			this->UpdateTargetLocation();
		}

		this->Owner_->SetActorLocation(DeltaLocation, true);
	}
}

void UGameMapMovementComponent::UpdateTargetLocation()
{
	if (this->Owner_ != nullptr)
	{
		const FVector CurrentLocation = this->Owner_->GetActorLocation();

		this->TargetLocation_ = CurrentLocation + FVector(0.f, 0.f, -10.f);
	}
}