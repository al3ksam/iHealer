// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapVirusAIController.h"

#include "iHealer/GameMap/Pawns/GameMapVirusPawn.h"

AGameMapVirusAIController::AGameMapVirusAIController()
{
}

// Called when the game starts or when spawned
void AGameMapVirusAIController::BeginPlay()
{
	AGameMapVirusPawn* Virus = Cast<AGameMapVirusPawn>(GetPawn());

	if (Virus)
	{
		Virus->StartRotate();
		Virus->StartWalking();
	}
}