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
	GameMapCameraComponent->OrthoWidth = 512.0f;
	GameMapCameraComponent->bConstrainAspectRatio = false;
}

// Called when the game starts or when spawned
void AGameMapCamera::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);

	if (PC)	PC->SetViewTarget(this); // Lock the camera position
}