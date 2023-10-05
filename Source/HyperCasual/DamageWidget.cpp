// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageWidget.h"
#include "Components/Border.h"

void UDamageWidget::MakeVisible(bool IsVisible)
{
	if (!Border)
	{
		UE_LOG(LogTemp, Error, TEXT("UDamageWidget::MakeVisible: Border is invalid"));
		return;
	}

	Border->SetRenderOpacity(IsVisible ? 0.5f : 0.0f);
}
