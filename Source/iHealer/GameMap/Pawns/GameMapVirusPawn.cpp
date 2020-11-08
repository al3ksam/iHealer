// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapVirusPawn.h"
#include "iHealer/GameMap/Components/GameMapMovementComponent.h"
#include "iHealer/GameMap/Components/GameMapRotatorComponent.h"
#include "iHealer/GameMap/Controllers/GameMapVirusAIController.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "PaperFlipbookComponent.h"
#include "TimerManager.h"

// Sets default values
AGameMapVirusPawn::AGameMapVirusPawn()
{
	// Set AI Controller
	AIControllerClass = AGameMapVirusAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

 	// Set this pawn to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;

	// Ignore the rotation from the controller
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));

	Mover = CreateDefaultSubobject<UGameMapMovementComponent>(TEXT("Mover"));
	Rotator = CreateDefaultSubobject<UGameMapRotatorComponent>(TEXT("Rotator"));
	
	if (SphereCollision)
	{
		SphereCollision->SetSphereRadius(34.f);
		SphereCollision->SetCollisionProfileName("Pawn");
		SphereCollision->BodyInstance.bLockYTranslation = true; // 2D-translation (XZ-axis)

		// 2D-rotation (XZ-axis)
		SphereCollision->BodyInstance.bLockXRotation = true;
		SphereCollision->BodyInstance.bLockZRotation = true;

		SetRootComponent(SphereCollision);

		if (Sprite)
		{
			Sprite->SetupAttachment(SphereCollision);
		}
	}
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
}