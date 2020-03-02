// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#include "GameMapCamera.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

AGameMapCamera::AGameMapCamera()
{
	// Setting up the camera component for an orthogonal view 
	UCameraComponent* GameMapCameraComponent = this->GetCameraComponent();
	GameMapCameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
	GameMapCameraComponent->OrthoWidth = 1024.0f;
	GameMapCameraComponent->bConstrainAspectRatio = false;
}

void AGameMapCamera::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);

	if (PC)	PC->SetViewTarget(this); // Lock the camera position
}