// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AActor* ASpawner::SingleSpawn(TSubclassOf<class AActor> ActorToSpawn)
{
	UWorld* World = GetWorld();
	if (!IsValid(World))
	{
		UE_LOG(LogTemp, Error, TEXT("ASpawner::SingleSpawn:Invalid World"));
		return nullptr;
	}

	if (!IsValid(ActorToSpawn))
	{
		UE_LOG(LogTemp, Error, TEXT("ASpawner::SingleSpawn:Invalid ActorToSpawn"));
		return nullptr;
	}

	AActor* SpawnedActor = World->SpawnActor<AActor>(ActorToSpawn, GetActorLocation(), GetActorRotation());

	return SpawnedActor;
}

