// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "iHealerGameModeBase.h"
#include "GameMap/Controllers/GameMapPlayerController.h"

AiHealerGameModeBase::AiHealerGameModeBase()
{
	// Default Player controller is the GameMap Player Controller
	PlayerControllerClass = AGameMapPlayerController::StaticClass();
	DefaultPawnClass = nullptr;
}