// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapVirusPawn.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "PaperFlipbookComponent.h"

// Sets default values
AGameMapVirusPawn::AGameMapVirusPawn()
{
	bNewRotation = false;

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SetRootComponent(Sphere);
	Sphere->BodyInstance.bLockYTranslation = true;
	Sphere->SetSimulatePhysics(true);
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

	UpdateRotation(DeltaTime);
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

void AGameMapVirusPawn::UpdateRotation(const float DeltaTime)
{
	if (!bNewRotation) return;

	FRotator ActorRotation = GetActorRotation();

	FRotator ActorNewRotation = FRotator(90.0f, 180.0f, 180.0f);

	bool bRotateCompleted = ActorRotation.Pitch >= ActorNewRotation.Pitch || ActorRotation.Pitch >= ActorNewRotation.Pitch - 1.0f;

	UE_LOG(LogTemp, Warning, TEXT("%s"), *(ActorRotation.ToString() + " | " + ActorNewRotation.ToString() + " | " + FString::FromInt(static_cast<int32>(bRotateCompleted))));

	if (bRotateCompleted)
	{
		bNewRotation = false;

		UE_LOG(LogTemp, Warning, TEXT("Stopped"));

		return;
	}
	
	FRotator ActorRotationTemp = FMath::RInterpTo(ActorRotation, ActorNewRotation, DeltaTime, this->RotationSpeed);
	this->SetActorRotation(ActorRotationTemp);
}

void AGameMapVirusPawn::OnTouch()
{
	bNewRotation = true;
}
