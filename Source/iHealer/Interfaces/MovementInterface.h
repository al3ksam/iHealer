// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MovementInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UMovementInterface : public UInterface
{
	GENERATED_BODY()
};

class IHEALER_API IMovementInterface
{
	GENERATED_BODY()

public:
	virtual void StartMoving() = 0;
	virtual void StopMoving() = 0;
	virtual bool isMoving() const = 0;
};
