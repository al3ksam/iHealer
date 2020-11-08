// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapVirusAIController.h"
#include "iHealer/GameMap/Pawns/GameMapVirusPawn.h"
#include "iHealer/GameMap/Components/GameMapRotatorComponent.h"
#include "iHealer/GameMap/Components/GameMapMovementComponent.h"

AGameMapVirusAIController::AGameMapVirusAIController()
{
}

// Called when the game starts or when spawned
void AGameMapVirusAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Overridable native function for when this controller possesses a pawn 
void AGameMapVirusAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AGameMapVirusPawn* const Virus = Cast<AGameMapVirusPawn>(InPawn);

	if (Virus == nullptr) return;

	UGameMapRotatorComponent* VirusRotatorComponent = Virus->GetRotatorComponent();
	UGameMapMovementComponent* VirusMoverComponent = Virus->GetMoverComponent();

	bool bLoadedComponents = VirusRotatorComponent != nullptr && VirusMoverComponent != nullptr;

	if (bLoadedComponents)
	{
		VirusRotatorComponent->StartRotating();
		VirusMoverComponent->StartMoving();
	}
}

// Overridable native function for when this controller unpossesses its pawn
void AGameMapVirusAIController::OnUnPossess()
{
	AGameMapVirusPawn* const Virus = Cast<AGameMapVirusPawn>(GetPawn());

	if (Virus == nullptr) return;

	UGameMapRotatorComponent* VirusRotatorComponent = Virus->GetRotatorComponent();
	UGameMapMovementComponent* VirusMoverComponent = Virus->GetMoverComponent();

	bool bLoadedComponents = VirusRotatorComponent != nullptr && VirusMoverComponent != nullptr;

	if (bLoadedComponents)
	{
		VirusRotatorComponent->StopRotating();
		VirusMoverComponent->StopMoving();
	}

	Super::OnUnPossess();
}