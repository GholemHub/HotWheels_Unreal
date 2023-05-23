// Fill out your copyright notice in the Description page of Project Settings.


#include "GameDataWidget.h"
#include "CHGameModeBase.h"

int32 UGameDataWidget::GetRoundSecondsRemaining() const
{
	const auto GameMode = CHGameModeBase();
	return GameMode ? GameMode->GetRoundSecondsRemaining(): 0;
}

ACHGameModeBase* UGameDataWidget::CHGameModeBase() const
{
	return GetWorld()? Cast<ACHGameModeBase>(GetWorld()->GetAuthGameMode()) : nullptr;
}
