// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameMapVirusPawn.generated.h"

namespace EVirusWalkingSpeeds
{
	using Type = float;

	const Type None   = 0.f;
	const Type Normal = 10.f;
	const Type Medium = 14.f;
	const Type Quick  = 18.f;
}

namespace EVirusRotationSpeeds
{
	using Type = float;

	const Type None   = 0.f;
	const Type Normal = 1.f;
	const Type Medium = 2.f;
	const Type Quick  = 3.f;
}

UCLASS()
class IHEALER_API AGameMapVirusPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGameMapVirusPawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void StartWalking();
	virtual void StopWalking();

	virtual void StartRotate();
	virtual void StopRotate();

	FORCEINLINE bool isWalking() { return bWalking_; }
	FORCEINLINE bool isRotating() { return bRotating_; }

protected:
	// Called after the actor's components have been initialized
	virtual void PostInitializeComponents() override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called when a Pawn is being removed
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;	

private:
	static EVirusRotationSpeeds::Type GetRandomRotationSpeed();

	void Walking(); // Change the Pawn position
	void Rotate(); // Change the Pawn rotation
	
	EVirusWalkingSpeeds::Type WalkingSpeed_ = EVirusWalkingSpeeds::None;
	EVirusRotationSpeeds::Type RotationSpeed_ = EVirusRotationSpeeds::None;

	bool bWalking_ = false;
	bool bRotating_ = false;

	FTimerHandle RotationTimerHandle_; // Timer handle for the rotation
	FTimerHandle WalkingTimerHandle_; // Timer handle for the walking 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* Sphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UPaperFlipbookComponent* Sprite;
};