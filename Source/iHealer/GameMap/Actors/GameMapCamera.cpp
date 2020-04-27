// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#include "GameMapCamera.h"
#include "Camera/CameraComponent.h"

AGameMapCamera::AGameMapCamera()
{
	UCameraComponent* GameMapCameraComponent = this->GetCameraComponent();

	// Setting the camera component for an orthogonal view 
	GameMapCameraComponent->SetProjectionMode(ECameraProjectionMode::Orthographic);
	GameMapCameraComponent->SetOrthoWidth(1024.f);
	GameMapCameraComponent->SetConstraintAspectRatio(false);
}