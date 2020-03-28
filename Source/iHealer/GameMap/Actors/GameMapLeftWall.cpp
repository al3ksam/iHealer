// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapLeftWall.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/Material.h"

// Sets default values
AGameMapLeftWall::AGameMapLeftWall()
{
 	// Set this actor to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh); 

	UStaticMesh* Cube = FindObject<UStaticMesh>(NULL, TEXT("/Game/GameMap/Meshes/Cube.Cube"));
	Mesh->SetStaticMesh(Cube);

	UMaterialInterface* Mat = FindObject<UMaterialInterface>(NULL, TEXT("/Game/GameMap/Materials/M_Wall.M_Wall"));	
	Mesh->SetMaterial(0, Mat);
}

// Called every frame
void AGameMapLeftWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called when the game starts or when spawned
void AGameMapLeftWall::BeginPlay()
{
	Super::BeginPlay();	
}