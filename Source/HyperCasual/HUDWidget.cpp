// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDWidget.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UHUDWidget::SetHealthPercent(float Percent)
{
	HealthBar->SetPercent(Percent / 100);
}

void UHUDWidget::SetScoreText(FText NewScoreText)
{
	ScoreText->SetText(NewScoreText);
}
