// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapVirusSpawnerActor.h"
#include "Components/BoxComponent.h"

// Sets default values
AGameMapVirusSpawnerActor::AGameMapVirusSpawnerActor()
{
 	// Set this actor to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = false;

	// Setting up
	Area = CreateDefaultSubobject<UBoxComponent>(TEXT("Area"));
	SetRootComponent(Area);
}

// Called every frame
void AGameMapVirusSpawnerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called when the game starts or when spawned
void AGameMapVirusSpawnerActor::BeginPlay()
{
	Super::BeginPlay();
	
}