// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapPlayerController.h"
#include "EngineUtils.h"
#include "iHealer/GameMap/Pawns/GameMapVirusPawn.h"

AGameMapPlayerController::AGameMapPlayerController()
{
}

// Called when the game starts
void AGameMapPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

bool AGameMapPlayerController::InputTouch(
	uint32 Handle, 
	ETouchType::Type Type, 
	const FVector2D& TouchLocation, 
	float Force, FDateTime DeviceTimestamp, 
	uint32 TouchpadIndex)
{
	Super::InputTouch(Handle, Type, TouchLocation, Force, DeviceTimestamp, TouchpadIndex);


	if (this->bTouched)	return false;

	
	for (TActorIterator<AGameMapVirusPawn> Virus(GetWorld()); Virus; ++Virus)
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *Virus->GetName());

		FString VirusName = Virus->GetName();
		
		if (VirusName != "Virus3") continue;

		bool bDestroyed = Virus->Destroy();

		UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::FromInt(static_cast<int32>(bDestroyed)));
	}


	bTouched = true;

	return false;
}
