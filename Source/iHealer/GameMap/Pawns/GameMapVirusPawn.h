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
	static constexpr float getMinSpeedRotation();
	static constexpr float getMaxSpeedRotation();

private:
	static constexpr float MIN_SPEED_ROTATION_ { 1.0f };
	static constexpr float MAX_SPEED_ROTATION_ { 10.0f };

public:
	// Sets default values for this pawn's properties
	AGameMapVirusPawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called when a Pawn is being removed
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* Sphere; 

	UPROPERTY(VisibleAnywhere)
	class UPaperFlipbookComponent* Sprite;

	UPROPERTY(EditAnywhere, Category="Pawn", Meta = (DisplayName = "Rotation speed", ClampMin="1.0", ClampMax="10.0"))
	float RotationSpeed;

private:
	// Change a Pawn rotation
	void Rotate();

	FTimerHandle RotationTimerHandle_;
};