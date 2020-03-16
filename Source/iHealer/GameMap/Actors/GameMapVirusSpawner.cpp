// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapVirusSpawner.h"
#include "Components/BoxComponent.h"

// Sets default values
AGameMapVirusSpawner::AGameMapVirusSpawner()
{
 	// Set this actor to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = false;

	// Setting up
	Area = CreateDefaultSubobject<UBoxComponent>(TEXT("Area"));
	SetRootComponent(Area);
	Area->SetGenerateOverlapEvents(false);
	Area->SetCollisionProfileName("NoCollision");
}

// Called every frame
void AGameMapVirusSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called when the game starts or when spawned
void AGameMapVirusSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}