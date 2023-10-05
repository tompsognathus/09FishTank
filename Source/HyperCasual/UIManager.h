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


protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Widgets")
	TSubclassOf<UUserWidget> FirstFishSelectorUIWidgetRef;


private:
	UUserWidget* FirstFishSelectorUIWidgetInstance;

};
