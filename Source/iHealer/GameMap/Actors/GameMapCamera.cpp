// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#include "GameMapCamera.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

AGameMapCamera::AGameMapCamera()
{
	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = false;

	// Setting the camera component for an orthogonal view 
	UCameraComponent* GameMapCameraComponent = this->GetCameraComponent();
	GameMapCameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
	GameMapCameraComponent->OrthoWidth = 1024.0f;
	GameMapCameraComponent->bConstrainAspectRatio = false;
}