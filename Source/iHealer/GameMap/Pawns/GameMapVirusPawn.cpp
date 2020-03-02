// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapVirusPawn.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "PaperFlipbookComponent.h"

// Sets default values
AGameMapVirusPawn::AGameMapVirusPawn()
{
	bNewRotation_ = false;

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

	UpdateRotation();
}

// Called to bind functionality to input
void AGameMapVirusPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UE_LOG(LogTemp, Warning, TEXT("Setup PI"));
}

// Called when the game starts or when spawned
void AGameMapVirusPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Update Pawn rotation if he have new rotation
void AGameMapVirusPawn::UpdateRotation(const float DeltaTime)
{
	if (!bNewRotation_) return;

	FRotator ActorRotation = GetActorRotation();

	FRotator ActorNewRotation = FRotator(90.0f, 180.0f, 180.0f);

	bool bRotateCompleted = ActorRotation.Pitch >= ActorNewRotation.Pitch || ActorRotation.Pitch >= ActorNewRotation.Pitch - 1.0f;

	UE_LOG(LogTemp, Warning, TEXT("%s"), *(ActorRotation.ToString() + " | " + ActorNewRotation.ToString() + " | " + FString::FromInt(static_cast<int32>(bRotateCompleted))));

	if (bRotateCompleted)
	{
		bNewRotation_ = false;

		UE_LOG(LogTemp, Warning, TEXT("Stopped"));

		return;
	}
	
	FRotator ActorRotationTemp = FMath::RInterpTo(ActorRotation, ActorNewRotation, DeltaTime, this->RotationSpeed);
	this->SetActorRotation(ActorRotationTemp);
}

void AGameMapVirusPawn::OnTouch()
{
	bNewRotation_ = true;
}
