// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapDestructionArea.h"
#include "Components/BoxComponent.h"
#include "iHealer/GameMap/Pawns/GameMapVirusPawn.h"

// Sets default values
AGameMapDestructionArea::AGameMapDestructionArea()
{
 	// Set this actor to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = false;

	Area = CreateDefaultSubobject<UBoxComponent>("Area");
	SetRootComponent(Area);

	Area->SetGenerateOverlapEvents(true);
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

	// Add overlap handle
	Area->OnComponentBeginOverlap.AddDynamic(this, &AGameMapDestructionArea::OnOverlap);
}

// Called when any object overlap this actor
void AGameMapDestructionArea::OnOverlap(
	UPrimitiveComponent* DestructionArea, AActor* Actor, UPrimitiveComponent* ActorComponent,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	bool bVirus = Actor->GetClass()->GetName() == AGameMapVirusPawn::StaticClass()->GetName();

	if (bVirus) Actor->Destroy();

	UE_LOG(LogTemp, Warning, TEXT("%s"), *Actor->GetName());
}
