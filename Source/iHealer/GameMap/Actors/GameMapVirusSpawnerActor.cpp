// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapVirusSpawnerActor.h"
#include "Components/BoxComponent.h"

// Sets default values
AGameMapVirusSpawnerActor::AGameMapVirusSpawnerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Area = CreateDefaultSubobject<UBoxComponent>(TEXT("Area"));

	SetRootComponent(Area);
}

// Called when the game starts or when spawned
void AGameMapVirusSpawnerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameMapVirusSpawnerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}