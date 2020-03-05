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

	static constexpr float MIN_SPEED_ROTATION = 1.0f;
	static constexpr float MAX_SPEED_ROTATION = 10.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* Sphere; 

	UPROPERTY(VisibleAnywhere)
	class UPaperFlipbookComponent* Sprite;

	UPROPERTY(EditAnywhere, Category="Pawn", Meta = (DisplayName = "Rotation speed", ClampMin="1.0", ClampMax="10.0"))
	float RotationSpeed;

private:
	void Rotate();
};