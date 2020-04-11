// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameMapVirusAIController.generated.h"

UCLASS()
class IHEALER_API AGameMapVirusAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AGameMapVirusAIController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Overridable native function for when this controller possesses a pawn 
	virtual void OnPossess(APawn* InPawn) override;

	// Overridable native function for when this controller unpossesses its pawn
	virtual void OnUnPossess() override;
};
