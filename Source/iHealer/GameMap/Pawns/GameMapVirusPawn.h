// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameMapVirusPawn.generated.h"

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
	void Walking(); // Change the Pawn position
	void Rotate(); // Change the Pawn rotation

	bool bWalking_ = false;
	bool bRotating_ = false;

	float WalkingSpeed_ = 0.f;
	float RotationSpeed_ = 0.f;

	TArray<float> RotationSpeeds_
	{
		1.f,
		2.f,
		3.f
	};

	FTimerHandle RotationTimerHandle_; // Timer handle for the rotation
	FTimerHandle WalkingTimerHandle_; // Timer handle for the walking 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* Sphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UPaperFlipbookComponent* Sprite;
};