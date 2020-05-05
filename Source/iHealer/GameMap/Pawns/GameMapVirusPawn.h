// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "iHealer/Interfaces/MovementInterface.h"
#include "iHealer/Interfaces/RotatorInterface.h"
#include "GameMapVirusPawn.generated.h"

namespace EVirusWalkingSpeeds
{
	using Type = float;

	const Type None   = 0.f;
	const Type Normal = 10.f;
	const Type Medium = 14.f;
	const Type Quick  = 18.f;
}

UCLASS()
class IHEALER_API AGameMapVirusPawn : public APawn
	, public IMovementInterface
	, public IRotatorInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGameMapVirusPawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	virtual void StartMove() override;

	UFUNCTION(BlueprintCallable)
	virtual void StopMove() override;

	UFUNCTION(BlueprintCallable)
	virtual void StartRotate() override;

	UFUNCTION(BlueprintCallable)
	virtual void StopRotate() override;

	UFUNCTION(BlueprintCallable)
	virtual bool isMoving() const override;

	UFUNCTION(BlueprintCallable)
	virtual bool isRotating() const override;

	FORCEINLINE class USphereComponent* GetSphereCollision() const { return SphereCollision; }
	FORCEINLINE class UPaperFlipbookComponent* GetSprite() const { return Sprite; }

protected:
	// Called after the actor's components have been initialized
	virtual void PostInitializeComponents() override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called when a Pawn is being removed
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;	

private:
	void Walking(); // Change the Pawn position
	
	EVirusWalkingSpeeds::Type WalkingSpeed_ = EVirusWalkingSpeeds::None;

	bool bWalking_ = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* SphereCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UPaperFlipbookComponent* Sprite;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UGameMapRotatorComponent* Rotator;
};