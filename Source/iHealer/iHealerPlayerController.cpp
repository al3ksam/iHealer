// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "iHealerPlayerController.h"
#include "EngineUtils.h"
#include "Engine/TextRenderActor.h"
#include "Components/TextRenderComponent.h"

#include "iHealer/GameMap/Pawns/GameMapVirusPawn.h"
#include "iHealer/GameMap/Actors/GameMapWall.h"

AiHealerPlayerController::AiHealerPlayerController()
{
}

// Called when the game starts or when spawned
void AiHealerPlayerController::BeginPlay()
{
	Super::BeginPlay();

	int32 SizeX = 0;
	int32 SizeY = 0;
	this->GetViewportSize(SizeX, SizeY);

	for (TActorIterator<ATextRenderActor> ActorIterator(GetWorld()); ActorIterator; ++ActorIterator)
	{
		ActorIterator->GetTextRender()->SetText(
			FText::FromString(FString::FromInt(SizeX) + "x" + FString::FromInt(SizeY))
		);
	}
}

// Test functionality game on touch
bool AiHealerPlayerController::InputTouch(
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

	int32 SizeX = 0;
	int32 SizeY = 0;
	this->GetViewportSize(SizeX, SizeY);

	UE_LOG(LogTemp, Warning, TEXT("Viewport size: %sx%s"),
		*FString::FromInt(SizeX),
		*FString::FromInt(SizeY)
	);

	for (TActorIterator<AGameMapWall> ActorIterator(GetWorld()); ActorIterator; ++ActorIterator)
	{

		if (ActorIterator->GetName() == "GameMapWallDown")
		{
			FVector ActorLocation = ActorIterator->GetActorLocation();
			FVector2D ScreenLocation = FVector2D(0.f, 0.f);
			bool bAccess = this->ProjectWorldLocationToScreen(ActorLocation, ScreenLocation);
			UE_LOG(LogTemp, Warning, TEXT("%s %s -> %s"),
				*ActorIterator->GetName(),
				*ScreenLocation.ToString(),
				*FString::FromInt(bAccess)
			);
		}
	}

	for (TActorIterator<ATextRenderActor> ActorIterator(GetWorld()); ActorIterator; ++ActorIterator)
	{
		ActorIterator->GetTextRender()->SetText(
			FText::FromString(FString::FromInt(SizeX) + "x" + FString::FromInt(SizeY))
		);
	}

	bTouched = true;

	return false;
}
