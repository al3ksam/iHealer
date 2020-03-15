// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapDestructionArea.h"
#include "Components/BoxComponent.h"

// Sets default values
AGameMapDestructionArea::AGameMapDestructionArea()
{
 	// Set this actor to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = false;

	// Setting up
	Area = CreateDefaultSubobject<UBoxComponent>("Area");
	SetRootComponent(Area);

	Area->SetCollisionProfileName("OverlapAll");
}

// Called every frame
void AGameMapDestructionArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called when the game starts or when spawned
void AGameMapDestructionArea::BeginPlay()
{
	Super::BeginPlay();
}