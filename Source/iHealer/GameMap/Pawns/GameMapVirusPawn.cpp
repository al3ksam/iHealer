// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapVirusPawn.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "PaperFlipbookComponent.h"
#include "TimerManager.h"

#include "iHealer/GameMap/Controllers/GameMapVirusAIController.h"

// Sets default values
AGameMapVirusPawn::AGameMapVirusPawn()
{
	// Set AI Controller
	AIControllerClass = AGameMapVirusAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

 	// Set this pawn to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = false;

	// Ignore the rotation from the controller
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SetRootComponent(SphereCollision);

	SphereCollision->SetSphereRadius(34.f);
	SphereCollision->SetCollisionProfileName("Pawn");
	SphereCollision->BodyInstance.bLockYTranslation = true; // 2D-translation (XZ-axis)

	// 2D-rotation (XZ-axis)
	SphereCollision->BodyInstance.bLockXRotation = true; 
	SphereCollision->BodyInstance.bLockZRotation = true;

	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	Sprite->SetupAttachment(SphereCollision);

	SetActorRotation(FRotator(0.f, 0.f, 0.f));
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

void AGameMapVirusPawn::StartWalking()
{
	if (this->bWalking_) return;

	GetWorld()->GetTimerManager()
		.SetTimer(this->WalkingTimerHandle_, this, &AGameMapVirusPawn::Walking, 0.04f, true);

	this->bWalking_ = true;
}

void AGameMapVirusPawn::StopWalking()
{
	if (!this->bWalking_) return;

	GetWorld()->GetTimerManager().ClearTimer(this->WalkingTimerHandle_);

	this->bWalking_ = false;
}

void AGameMapVirusPawn::StartRotate()
{
	if (this->bRotating_) return;

	this->RotationSpeed_ = AGameMapVirusPawn::GetRandomRotationSpeed();

	GetWorld()->GetTimerManager()
		.SetTimer(this->RotationTimerHandle_, this, &AGameMapVirusPawn::Rotate, 0.04f, true);

	this->bRotating_ = true;
}

void AGameMapVirusPawn::StopRotate()
{
	if (!this->bRotating_) return;

	GetWorld()->GetTimerManager().ClearTimer(this->RotationTimerHandle_);

	this->bRotating_ = false;
}

// Called after the actor's components have been initialized
void AGameMapVirusPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	// Setting physics
	SphereCollision->SetMassOverrideInKg(NAME_None, 10.0f);
	SphereCollision->SetEnableGravity(false);
	SphereCollision->SetSimulatePhysics(true); // Enable physics
}

// Called when the game starts or when spawned
void AGameMapVirusPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called when a Pawn is being removed
void AGameMapVirusPawn::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (this->bWalking_) this->StopWalking();
	if (this->bRotating_) this->StopRotate();
}

EVirusRotationSpeeds::Type AGameMapVirusPawn::GetRandomRotationSpeed()
{
	TArray<EVirusRotationSpeeds::Type> Speeds
	{
		EVirusRotationSpeeds::Normal,
		EVirusRotationSpeeds::Medium,
		EVirusRotationSpeeds::Quick
	};

	uint8 SpeedIndex = FMath::RandRange(0, Speeds.Num() - 1);

	return Speeds[SpeedIndex];
}

// Change the Pawn position
void AGameMapVirusPawn::Walking()
{
	this->AddActorWorldOffset(FVector(0.f, 0.f, -1.f * this->WalkingSpeed_), true);
}

// Change the Pawn rotation
void AGameMapVirusPawn::Rotate()
{
	this->AddActorLocalRotation(FRotator(1.f * this->RotationSpeed_, 0.f, 0.f), true);
}