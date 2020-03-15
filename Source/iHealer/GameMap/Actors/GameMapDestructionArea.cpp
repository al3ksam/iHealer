// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapDestructionArea.h"

// Sets default values
AGameMapDestructionArea::AGameMapDestructionArea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameMapDestructionArea::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameMapDestructionArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

