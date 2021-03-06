// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "iHealerPlayerController.generated.h"

UCLASS()
class IHEALER_API AiHealerPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AiHealerPlayerController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Test functionality game on touch
	virtual bool InputTouch(
		uint32 Handle, 
		ETouchType::Type Type, 
		const FVector2D& TouchLocation,
		float Force,
		FDateTime DeviceTimestamp,
		uint32 TouchpadIndex
	) override;

private:
	bool bTouched { false };
};
