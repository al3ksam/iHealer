// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapVirusPawn.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "PaperFlipbookComponent.h"
#include "TimerManager.h"

constexpr float AGameMapVirusPawn::getMinSpeedRotation()
{
	return AGameMapVirusPawn::MIN_SPEED_ROTATION_;
}

constexpr float AGameMapVirusPawn::getMaxSpeedRotation()
{
	return AGameMapVirusPawn::MAX_SPEED_ROTATION_;
}

// Sets default values
AGameMapVirusPawn::AGameMapVirusPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Ignore the rotation from the controller
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SetRootComponent(Sphere);
	Sphere->BodyInstance.bLockYTranslation = true; // 2D-translation (XZ-axis)

	// Configure Pawn physics
	Sphere->SetSimulatePhysics(true);
	Sphere->SetMassOverrideInKg(NAME_None, 10.0f);
	Sphere->SetEnableGravity(false);

	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	Sprite->SetupAttachment(Sphere);

	RotationSpeed = 2.f;

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

// Called when the game starts or when spawned
void AGameMapVirusPawn::BeginPlay()
{
	Super::BeginPlay();

	// Start to rotate the Pawn
	GetWorld()->GetTimerManager().SetTimer(this->RotationTimerHandle_, this, &AGameMapVirusPawn::Rotate, 2.f, true);
}

// Called when a Pawn is being removed
void AGameMapVirusPawn::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// Stop to rotate the Pawn
	GetWorld()->GetTimerManager().ClearTimer(this->RotationTimerHandle_);
}

// Change a Pawn rotation
void AGameMapVirusPawn::Rotate()
{
	UE_LOG(LogTemp, Warning, TEXT("Rotate %s"),
		*this->GetName()
	);
}