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
};
