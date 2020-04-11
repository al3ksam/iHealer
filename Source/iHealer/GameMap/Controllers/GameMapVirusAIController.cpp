// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapVirusAIController.h"

#include "iHealer/GameMap/Pawns/GameMapVirusPawn.h"

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

	AGameMapVirusPawn* Virus = Cast<AGameMapVirusPawn>(InPawn);

	if (Virus != nullptr)
	{
		Virus->StartRotate();
		Virus->StartWalking();
	}
}

// Overridable native function for when this controller unpossesses its pawn
void AGameMapVirusAIController::OnUnPossess()
{
	Super::OnUnPossess();
}