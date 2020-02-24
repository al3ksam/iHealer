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
	virtual void BeginPlay() override;
};
