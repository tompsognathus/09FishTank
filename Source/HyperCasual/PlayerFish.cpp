// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFish.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
APlayerFish::APlayerFish()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerFish::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void APlayerFish::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Print actor name
	UE_LOG(LogTemp, Warning, TEXT("Actor name: %s"), *GetName());
}

// Called to bind functionality to input
void APlayerFish::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (!IsValid(EnhancedInputComponent))
	{
		UE_LOG(LogTemp, Error, TEXT("APlayerFish::SetupPlayerInputComponent: Invalid EnhancedInputComponent"));
		return;
	}

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerFish::Move);

}

void APlayerFish::Move(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Error, TEXT("Moving"));
}
