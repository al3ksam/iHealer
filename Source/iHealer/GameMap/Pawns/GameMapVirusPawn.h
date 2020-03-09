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
	void EnableAutoRotate();
	void DisableAutoRotate();

	// Change a Pawn rotation
	void Rotate();

	FTimerHandle RotationTimerHandle_;
};