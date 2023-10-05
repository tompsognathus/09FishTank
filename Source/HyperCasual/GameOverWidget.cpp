// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverWidget.h"
#include "Components/TextBlock.h"

void UGameOverWidget::SetScoreText(FText NewScoreText)
{
	ScoreText->SetText(NewScoreText);
}
