// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "iHealer/GameMap/Pawns/GameMapVirusPawn.h"
#include "Engine/World.h"
#include "EngineUtils.h"

AGameMapPlayerController::AGameMapPlayerController()
{
	this->bTouched = false;
}

void AGameMapPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

bool AGameMapPlayerController::InputTouch(uint32 Handle, ETouchType::Type Type, 
	const FVector2D& TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex)
{
	Super::InputTouch(Handle, Type, TouchLocation, Force, DeviceTimestamp, TouchpadIndex);

	if (!bTouched)
	{

		for (TActorIterator<AGameMapVirusPawn> VirusPawn(GetWorld()); VirusPawn; ++VirusPawn)
		{
			VirusPawn->OnTouch();
		}
		
		bTouched = true;
	}	

	return false;
}