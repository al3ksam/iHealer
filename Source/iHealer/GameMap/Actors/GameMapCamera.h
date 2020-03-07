// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "GameMapCamera.generated.h"

UCLASS()
class IHEALER_API AGameMapCamera : public ACameraActor
{
	GENERATED_BODY()

public:
	AGameMapCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
