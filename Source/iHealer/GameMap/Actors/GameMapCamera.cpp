// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#include "GameMapCamera.h"
#include "Camera/CameraComponent.h"

AGameMapCamera::AGameMapCamera()
{
	UCameraComponent* GameMapCameraComponent = this->GetCameraComponent();

	// Setting the camera component for an orthogonal view 
	GameMapCameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
	GameMapCameraComponent->OrthoWidth = 1024.0f;
	GameMapCameraComponent->bConstrainAspectRatio = false;
}