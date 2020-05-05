// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "iHealer/Interfaces/RotatorInterface.h"
#include "GameMapRotatorComponent.generated.h"

namespace EVirusRotationSpeeds
{
	using Type = float;

	const Type None = 0.f;
	const Type Normal = 0.5f;
	const Type Medium = 1.f;
	const Type Quick = 2.f;
}

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class IHEALER_API UGameMapRotatorComponent : public UActorComponent, public IRotatorInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGameMapRotatorComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, 
		FActorComponentTickFunction* ThisTickFunction) override;

	virtual void StartRotate() override; // Start rotate the pawn
	virtual void StopRotate() override; // Stop rotate the pawn

	virtual bool isRotating() const override; // Returns the pawn rotation state

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	static EVirusRotationSpeeds::Type GetRandomRotationSpeed();

	void Rotate(float DeltaTime); // Rotate the Pawn

	void UpdateTargetRotation();

	class AActor* Owner_ = nullptr;

	FQuat TargetRotation_ = FQuat(0.f, 0.f, 0.f, 0.f);

	EVirusRotationSpeeds::Type RotationSpeed_ = EVirusRotationSpeeds::None;

	bool bCanRotate_ = false;
	bool bRotating_ = false;
};