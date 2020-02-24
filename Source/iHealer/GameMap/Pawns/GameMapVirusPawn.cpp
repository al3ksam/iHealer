// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapVirusPawn.h"
#include "Components/SphereComponent.h"
#include "PaperFlipbookComponent.h"

// Sets default values
AGameMapVirusPawn::AGameMapVirusPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));

	SetRootComponent(Sphere);

	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	
	Sprite->SetupAttachment(Sphere);
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
	
}