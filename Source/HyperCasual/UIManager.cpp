// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"

#include "Blueprint/UserWidget.h"

AUIManager::AUIManager()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AUIManager::OpenFirstFishSelectorUI()
{
	UWorld* World = GetWorld();
	if (!IsValid(World))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::OpenFirstFishSelectorUI: World is not valid"));
		return;
	}

	FirstFishSelectorUIWidgetInstance = CreateWidget(GetWorld(), FirstFishSelectorUIWidgetRef);
	FirstFishSelectorUIWidgetInstance->AddToViewport();
}

void AUIManager::CloseFirstFishSelectorUI()
{
	if (!IsValid(FirstFishSelectorUIWidgetInstance))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::CloseFirstFishSelectorUI: FirstFishSelectorUIWidgetInstance is not valid"));
		return;
	}

	FirstFishSelectorUIWidgetInstance->RemoveFromParent();
	FirstFishSelectorUIWidgetInstance = nullptr;
}

void AUIManager::BeginPlay()
{
	Super::BeginPlay();
	
}

