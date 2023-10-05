// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UIManager.generated.h"

class UUserWidget;

UCLASS()
class HYPERCASUAL_API AUIManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AUIManager();
	
	UFUNCTION(BlueprintCallable, Category = "UI Functions")
	void OpenFirstFishSelectorUI();

	UFUNCTION(BlueprintCallable, Category = "UI Functions")
	void CloseFirstFishSelectorUI();

	UFUNCTION(BlueprintCallable, Category = "UI Functions")
	void OpenDamageUI();

	UFUNCTION(BlueprintCallable, Category = "UI Functions")
	void CloseDamageUI();

	UFUNCTION(BlueprintCallable, Category = "UI Functions")
	void OpenHUDUI();

	UFUNCTION(BlueprintCallable, Category = "UI Functions")
	void CloseHUDUI();

	UFUNCTION(BlueprintCallable, Category = "UI Functions")
	void OpenGameOverUI();

	UFUNCTION(BlueprintCallable, Category = "UI Functions")
	void CloseGameOverUI();

	UFUNCTION(BlueprintCallable, Category = "UI Functions")
	void SetHpBarPercent(float Percent);

	UFUNCTION(BlueprintCallable, Category = "UI Functions")
	void SetHUDScoreText(FText NewScoreText);

	UFUNCTION(BlueprintCallable, Category = "UI Functions")
	void SetGameOverScoreText(FText NewScoreText);

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Widgets")
	TSubclassOf<UUserWidget> FirstFishSelectorUIWidgetRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Widgets")
	TSubclassOf<UUserWidget> DamageUIWidgetRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Widgets")
	TSubclassOf<UUserWidget> HUDWidgetRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Widgets")
	TSubclassOf<UUserWidget> GameOverWidgetRef;

private:
	UUserWidget* FirstFishSelectorUIWidgetInstance;
	UUserWidget* DamageUIWidgetInstance;
	UUserWidget* HUDWidgetInstance;
	UUserWidget* GameOverWidgetInstance;

};
