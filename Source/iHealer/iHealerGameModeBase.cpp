// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "iHealerGameModeBase.h"
#include "iHealerPlayerController.h"

AiHealerGameModeBase::AiHealerGameModeBase()
{
	// Default Player controller is the GameMap Player Controller
	PlayerControllerClass = AiHealerPlayerController::StaticClass();
	DefaultPawnClass = nullptr;
}