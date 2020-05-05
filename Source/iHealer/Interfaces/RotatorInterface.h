// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RotatorInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class URotatorInterface : public UInterface
{
	GENERATED_BODY()
};

class IHEALER_API IRotatorInterface
{
	GENERATED_BODY()

public:
	virtual void StartRotate() = 0;
	virtual void StopRotate() = 0;
	virtual bool isRotating() const = 0;
};
