// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameMapPlayerController.generated.h"

UCLASS()
class IHEALER_API AGameMapPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AGameMapPlayerController();

protected:
	virtual void BeginPlay() override;
};
