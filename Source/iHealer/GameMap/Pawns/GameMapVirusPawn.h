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

protected:
	// Called after the actor's components have been initialized
	virtual void PostInitializeComponents() override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called when a Pawn is being removed
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* Sphere; 

	UPROPERTY(VisibleAnywhere)
	class UPaperFlipbookComponent* Sprite;

private:
	void StartWalking();
	void StopWalking();
	void Walking(); // Change the Pawn position
	void EnableAutoRotate();
	void DisableAutoRotate();
	void Rotate(); // Change the Pawn rotation

	FTimerHandle RotationTimerHandle_; // Timer handle for the rotation
	FTimerHandle WalkingTimerHandle_; // Timer handle for the walking 
};