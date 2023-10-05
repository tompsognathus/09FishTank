// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class HYPERCASUAL_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawner();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Spawner")
	AActor* SingleSpawn(TSubclassOf<class AActor> ActorToSpawn);


protected:
	virtual void BeginPlay() override;


};
