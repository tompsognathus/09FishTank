// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

class UTextBlock;
UCLASS()
class HYPERCASUAL_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "HUD")
	void SetScoreText(FText NewScoreText);

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* ScoreText;
};
