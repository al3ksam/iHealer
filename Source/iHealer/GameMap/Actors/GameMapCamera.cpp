// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#include "GameMapCamera.h"
#include "Kismet/GameplayStatics.h"

AGameMapCamera::AGameMapCamera()
{
}

void AGameMapCamera::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);

	if (PC)
	{
		PC->SetViewTarget(this);
	}
}