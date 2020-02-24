// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "VirusSpawnerActor.h"
#include "Components/BoxComponent.h"

// Sets default values
AVirusSpawnerActor::AVirusSpawnerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Area = CreateDefaultSubobject<UBoxComponent>(TEXT("Area"));

	SetRootComponent(Area);
}

// Called when the game starts or when spawned
void AVirusSpawnerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVirusSpawnerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

