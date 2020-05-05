// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "iHealer/Interfaces/RotatorInterface.h"
#include "GameMapRotatorComponent.generated.h"

namespace ERotationSpeeds
{
	using Type = float;

	const Type None = 0.f;
	const Type Normal = 0.5f;
	const Type Medium = 1.f;
	const Type Quick = 2.f;
}

struct RotationsSpeeds final
{
	/** Returns the number of speeds  */
	static constexpr int Count()
	{
		return 3;
	}

	/** Returns an array of speeds */
	static const ERotationSpeeds::Type* Get()
	{
		static const ERotationSpeeds::Type Speeds[]
		{
			ERotationSpeeds::Normal,
			ERotationSpeeds::Medium,
			ERotationSpeeds::Quick
		};

		return Speeds;
	}

	/** Returns a random speed */
	static const ERotationSpeeds::Type GetRandom()
	{
		const uint8 SpeedIndex = FMath::RandRange(0, RotationsSpeeds::Count() - 1);

		return RotationsSpeeds::Get()[SpeedIndex];
	}

	RotationsSpeeds(const RotationsSpeeds&) = delete;
	RotationsSpeeds& operator=(const RotationsSpeeds&) = delete;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class IHEALER_API UGameMapRotatorComponent 
	: public UActorComponent
	, public IRotatorInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGameMapRotatorComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, 
		FActorComponentTickFunction* ThisTickFunction) override;

	virtual void StartRotating() override;
	virtual void StopRotating() override; 
	virtual bool isRotating() const override; 

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	void Rotate(float DeltaTime);
	
	void UpdateTargetRotation();

	class AActor* Owner_ = nullptr;

	FQuat TargetRotation_ = FQuat(0.f, 0.f, 0.f, 0.f);

	ERotationSpeeds::Type RotationSpeed_ = ERotationSpeeds::None;

	bool bCanRotate_ = false;
	bool bRotating_ = false;
};