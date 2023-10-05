// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"

#include "Blueprint/UserWidget.h"
#include "DamageWidget.h"
#include "GameOverWidget.h"
#include "Components/Border.h"
#include "HUDWidget.h"


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

void AUIManager::OpenDamageUI()
{
	if (!IsValid(DamageUIWidgetRef))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::OpenDamageUI: Invalid DamageUIWidgetRef"));
		return;
	}

	UWorld* World = GetWorld();
	if (!IsValid(World))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::OpenDamageUI: World is not valid"));
		return;
	}

	if (!IsValid(DamageUIWidgetInstance))
	{
		DamageUIWidgetInstance = CreateWidget(World, DamageUIWidgetRef);
		if (!IsValid(DamageUIWidgetInstance))
		{
			UE_LOG(LogTemp, Error, TEXT("AUIManager::OpenDamageUI: DamageUIWidgetInstance is not valid"));
			return;
		}

		DamageUIWidgetInstance->AddToViewport();
	}

	UDamageWidget* DamageWidget = Cast<UDamageWidget>(DamageUIWidgetInstance);

	if (!IsValid(DamageWidget))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::OpenDamageUI: DamageWidget is not valid"));
		return;
	}

	DamageWidget->MakeVisible(true);
}

void AUIManager::CloseDamageUI()
{
	if (!IsValid(DamageUIWidgetInstance))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::CloseDamageUI: DamageUIWidgetInstance is not valid"));
		return;
	}

	UDamageWidget* DamageWidget = Cast<UDamageWidget>(DamageUIWidgetInstance);

	if (!IsValid(DamageWidget))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::OpenDamageUI: DamageWidget is not valid"));
		return;
	}

	DamageWidget->MakeVisible(false);

}

void AUIManager::OpenHUDUI()
{
	if (!IsValid(HUDWidgetRef))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::OpenHUDUI: Invalid HUDWidgetRef"));
		return;
	}

	UWorld* World = GetWorld();
	if (!IsValid(World))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::OpenHUDUI: World is not valid"));
		return;
	}

	if (!IsValid(HUDWidgetInstance))
	{
		HUDWidgetInstance = CreateWidget(World, HUDWidgetRef);
		if (!IsValid(HUDWidgetInstance))
		{
			UE_LOG(LogTemp, Error, TEXT("AUIManager::OpenHUDUI: HUDWidgetInstance is not valid"));
			return;
		}

		HUDWidgetInstance->AddToViewport();
	}
}

void AUIManager::CloseHUDUI()
{
	if (!IsValid(HUDWidgetInstance))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::CloseHUDUI: HUDWidgetInstance is not valid"));
		return;
	}

	HUDWidgetInstance->RemoveFromParent();
	HUDWidgetInstance = nullptr;
}

void AUIManager::OpenGameOverUI()
{
	if (!IsValid(GameOverWidgetRef))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::OpenGameOverUI: Invalid GameOverWidgetRef"));
		return;
	}

	UWorld* World = GetWorld();
	if (!IsValid(World))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::OpenGameOverUI: World is not valid"));
		return;
	}

	if (!IsValid(GameOverWidgetInstance))
	{
		GameOverWidgetInstance = CreateWidget(World, GameOverWidgetRef);
		if (!IsValid(GameOverWidgetInstance))
		{
			UE_LOG(LogTemp, Error, TEXT("AUIManager::OpenGameOverUI: GameOverWidgetInstance is not valid"));
			return;
		}

		GameOverWidgetInstance->AddToViewport();
	}
}

void AUIManager::CloseGameOverUI()
{
	if (!IsValid(GameOverWidgetInstance))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::CloseGameOverUI: GameOverWidgetInstance is not valid"));
		return;
	}

	GameOverWidgetInstance->RemoveFromParent();
	GameOverWidgetInstance = nullptr;
}

void AUIManager::SetHpBarPercent(float Percent)
{
	if (!IsValid(HUDWidgetInstance))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::SetHpBarPercent: Invalid HUDWidgetInstance"));
		return;
	}

	UHUDWidget* HUDWidget = Cast<UHUDWidget>(HUDWidgetInstance);

	if (!IsValid(HUDWidget))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::SetHpBarPercent: Invalid HUDWidget"));
		return;
	}

	HUDWidget->SetHealthPercent(Percent);

}

void AUIManager::SetHUDScoreText(FText NewScoreText)
{
	if (!IsValid(HUDWidgetInstance))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::SetScoreText: Invalid HUDWidgetInstance"));
		return;
	}

	UHUDWidget* HUDWidget = Cast<UHUDWidget>(HUDWidgetInstance);

	if (!IsValid(HUDWidget))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::SetScoreText: Invalid HUDWidget"));
		return;
	}

	HUDWidget->SetScoreText(NewScoreText);
}

void AUIManager::SetGameOverScoreText(FText NewScoreText)
{
	if (!IsValid(GameOverWidgetInstance))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::SetGameOverScoreText: Invalid GameOverWidgetInstance"));
		return;
	}

	UGameOverWidget* GameOverWidget = Cast<UGameOverWidget>(GameOverWidgetInstance);
	if (!IsValid(GameOverWidget))
	{
		UE_LOG(LogTemp, Error, TEXT("AUIManager::SetGameOverScoreText: Invalid GameOverWidget"));
		return;
	}

	GameOverWidget->SetScoreText(NewScoreText);
}

void AUIManager::BeginPlay()
{
	Super::BeginPlay();
	
}

