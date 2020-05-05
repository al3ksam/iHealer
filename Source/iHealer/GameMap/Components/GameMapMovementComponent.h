// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "iHealer/Interfaces/MovementInterface.h"
#include "GameMapMovementComponent.generated.h"

namespace EMovementSpeeds
{
	using Type = float;

	const Type None = 0.f;
	const Type Normal = 40.f;
	const Type Medium = 60.f;
	const Type Quick = 80.f;
}

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class IHEALER_API UGameMapMovementComponent 
	: public UActorComponent
	, public IMovementInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGameMapMovementComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, 
		FActorComponentTickFunction* ThisTickFunction) override;

	virtual void StartMoving() override;
	virtual void StopMoving() override;
	virtual bool isMoving() const override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	static EMovementSpeeds::Type GetRandomMovementSpeed();

	void Move(float DeltaTime);

	void UpdateTargetLocation();

	class AActor* Owner_ = nullptr;

	FVector TargetLocation_ = FVector(0.f, 0.f, 0.f);

	EMovementSpeeds::Type MovementSpeed_ = EMovementSpeeds::None;

	bool bCanMove_ = false;
	bool bMoving_ = false;
};