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
	const Type Normal = 0.5f;
	const Type Medium = 1.f;
	const Type Quick  = 2.f;
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

	UFUNCTION(BlueprintCallable)
	virtual void StartWalking();

	UFUNCTION(BlueprintCallable)
	virtual void StopWalking();

	UFUNCTION(BlueprintCallable)
	virtual void StartRotate();

	UFUNCTION(BlueprintCallable)
	virtual void StopRotate();

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool isWalking() const { return this->bWalking_; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool isRotating() const { return this->bRotating_; }

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
	static EVirusRotationSpeeds::Type GetRandomRotationSpeed();

	void UpdateRotationSpeed();
	EVirusRotationSpeeds::Type GetRotationSpeed() const;

	void UpdateTargetRotation();
	FQuat GetTargetRotation();

	FORCEINLINE bool CanRotate() const { return this->bCanRotate_; }

	void Walking(); // Change the Pawn position
	void Rotate(float DeltaTime); // Change the Pawn rotation

	FQuat TargetRotation_ = FQuat(0.f, 0.f, 0.f, 0.f);

	bool bCanRotate_ = false;
	
	EVirusWalkingSpeeds::Type WalkingSpeed_ = EVirusWalkingSpeeds::None;
	EVirusRotationSpeeds::Type RotationSpeed_ = EVirusRotationSpeeds::None;

	bool bWalking_ = false;
	bool bRotating_ = false;

	FTimerHandle WalkingTimerHandle_; // Timer handle for the walking 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* SphereCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UPaperFlipbookComponent* Sprite;
};