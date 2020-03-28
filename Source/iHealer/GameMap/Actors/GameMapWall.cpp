// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapWall.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AGameMapWall::AGameMapWall()
{
 	// Set this actor to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh); 

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(TEXT("/Game/GameMap/Meshes/Cube.Cube"));

	Mesh->SetStaticMesh(Cube.Object);
}

// Called every frame
void AGameMapWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called when the game starts or when spawned
void AGameMapWall::BeginPlay()
{
	Super::BeginPlay();	
}