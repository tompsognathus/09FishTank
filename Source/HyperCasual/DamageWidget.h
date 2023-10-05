// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DamageWidget.generated.h"

class UBorder;

UCLASS()
class HYPERCASUAL_API UDamageWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void MakeVisible(bool IsVisible);

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UBorder* Border;
};
