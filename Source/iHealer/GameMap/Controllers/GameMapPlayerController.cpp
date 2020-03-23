// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapPlayerController.h"
#include "EngineUtils.h"
#include "iHealer/GameMap/Pawns/GameMapVirusPawn.h"
#include "UnrealEngine.h"

AGameMapPlayerController::AGameMapPlayerController()
{
}

// Called when the game starts or when spawned
void AGameMapPlayerController::BeginPlay()
{
	Super::BeginPlay();

	int32 SizeX = 0;
	int32 SizeY = 0;
	this->GetViewportSize(SizeX, SizeY);

	FVector2D Resolution = FVector2D(GSystemResolution.ResX, GSystemResolution.ResY);

	UE_LOG(LogTemp, Warning, TEXT("%sx%s"),
		*FString::FromInt(Resolution.X),
		*FString::FromInt(Resolution.Y)
	);
}

// Test functionality game on touch
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
	}

	bTouched = true;

	return false;
}
