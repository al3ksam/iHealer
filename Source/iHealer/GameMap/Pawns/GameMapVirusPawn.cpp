// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapVirusPawn.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "PaperFlipbookComponent.h"
#include "TimerManager.h"

// Sets default values
AGameMapVirusPawn::AGameMapVirusPawn()
{
 	// Set this pawn to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = false;

	// Ignore the rotation from the controller
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SetRootComponent(Sphere);
	Sphere->SetCollisionProfileName("Pawn");
	Sphere->BodyInstance.bLockYTranslation = true; // 2D-translation (XZ-axis)
	Sphere->BodyInstance.bLockXRotation = true; // 2D-rotation (XZ-axis)
	Sphere->BodyInstance.bLockZRotation = true; // 2D-rotation (XZ-axis)

	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	Sprite->SetupAttachment(Sphere);

	SetActorRotation(FRotator(-90.f, 0.0f, 0.0f));
}

// Called every frame
void AGameMapVirusPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGameMapVirusPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// Called after the actor's components have been initialized
void AGameMapVirusPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	// Configure Pawn physics
	Sphere->SetSimulatePhysics(true);
	Sphere->SetMassOverrideInKg(NAME_None, 10.0f);
	Sphere->SetEnableGravity(false);
}

// Called when the game starts or when spawned
void AGameMapVirusPawn::BeginPlay()
{
	Super::BeginPlay();

	this->StartRotate();
	this->StartWalking();
}

// Called when a Pawn is being removed
void AGameMapVirusPawn::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	
	this->StopRotate();
	this->StopWalking();
}

// Change the Pawn position
void AGameMapVirusPawn::Walking()
{
	this->AddActorWorldOffset(FVector(2.f, 0.f, 0.f), true);
}

// Change the Pawn rotation
void AGameMapVirusPawn::Rotate()
{
	this->AddActorLocalRotation(FRotator(1.f, 0.f, 0.f), true);
}

void AGameMapVirusPawn::StartWalking()
{
	GetWorld()->GetTimerManager()
		.SetTimer(this->WalkingTimerHandle_, this, &AGameMapVirusPawn::Walking, 0.02f, true);
}

void AGameMapVirusPawn::StopWalking()
{
	GetWorld()->GetTimerManager().ClearTimer(this->WalkingTimerHandle_);
}

void AGameMapVirusPawn::StartRotate()
{
	// Rotation speeds
	TArray<float> const RSpeeds {
		0.04f, // NORMAL
		0.02f, // FASTER
		0.01f  // VERY FAST
	};

	// Get random index of the rotation speed
	const enum ERotationSpeedIndex {
		NORMAL,
		FASTER,
		VERY_FAST
	} RotationSpeedIndex = static_cast<ERotationSpeedIndex>(
		FMath::RandRange(ERotationSpeedIndex::NORMAL, ERotationSpeedIndex::VERY_FAST)
	);

	float RotationSpeed = RSpeeds[RotationSpeedIndex];

	UE_LOG(LogTemp, Warning, TEXT("Rotation speed of %s: %s"),
		*this->GetName(),
		*FString::FromInt(RotationSpeedIndex)
	);

	// Start to rotate the Pawn
	GetWorld()->GetTimerManager()
		.SetTimer(this->RotationTimerHandle_, this, &AGameMapVirusPawn::Rotate, RotationSpeed, true);
}

void AGameMapVirusPawn::StopRotate()
{
	// Stop to rotate the Pawn
	GetWorld()->GetTimerManager().ClearTimer(this->RotationTimerHandle_);
}