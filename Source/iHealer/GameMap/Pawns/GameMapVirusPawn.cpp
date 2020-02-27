// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.


#include "GameMapVirusPawn.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/Controller.h"

// Sets default values
AGameMapVirusPawn::AGameMapVirusPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));

	SetRootComponent(Sphere);

	//Sphere->SetUsingAbsoluteRotation(true);

	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	
	Sprite->SetupAttachment(Sphere);

	UE_LOG(LogTemp, Warning, TEXT("AGameMapVirusPawn: %s"), *this->GetName());
}

// Called every frame
void AGameMapVirusPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGameMapVirusPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UE_LOG(LogTemp, Warning, TEXT("Setup PI"));
}

// Called when the game starts or when spawned
void AGameMapVirusPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGameMapVirusPawn::OnTouch()
{
	FRotator r1 = this->GetActorRotation();


	UE_LOG(LogTemp, Warning, TEXT("%s"), *r1.ToString());

	this->SetActorRotation(FRotator(10.0f, 0.0f, 0.0f));

	FRotator r2 = this->GetActorRotation();


	UE_LOG(LogTemp, Warning, TEXT("* %s"), *r2.ToString());

	UE_LOG(LogTemp, Warning, TEXT("%s"), *Controller->GetClass()->GetFullName());

	UE_LOG(LogTemp, Warning, TEXT("%s"), *Controller->GetPawn()->GetClass()->GetFullName());
}
