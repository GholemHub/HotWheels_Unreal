// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameOwerWidget.h"
#include "Blueprint/UserWidget.h"
#include "CHGameModeBase.h"
#include "VehocleProject/Character/C_CH_CarBase.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UGameOwerWidget::SetroundTime(const FText& Time)
{
	if (!RoundTimeText) return;

	RoundTimeText->SetText(Time);
}

int32 UGameOwerWidget::GetRoundSecondsRemaining() const
{
	const auto GameMode = CHGameModeBase();
	return GameMode ? GameMode->GetRoundSecondsRemaining() : 0;
}

ACHGameModeBase* UGameOwerWidget::CHGameModeBase() const
{
	return GetWorld() ? Cast<ACHGameModeBase>(GetWorld()->GetAuthGameMode()) : nullptr;
}


void UGameOwerWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (ResetLevelButton)
	{
		ResetLevelButton->OnClicked.AddDynamic(this, &UGameOwerWidget::OnResenLevel);
	}

	if (GetWorld())
	{
		const auto GameMode = CHGameModeBase();
		if (GameMode)
		{
			GameMode->OnMatchStateChanged.AddUObject(this, &UGameOwerWidget::OnMatchStateChanged);
		}
	}
}

void UGameOwerWidget::OnMatchStateChanged(EMatchState State)
{
	if (GetWorld()) {
		int32 Minutes = GetRoundSecondsRemaining() / 60;
		int32 Seconds = GetRoundSecondsRemaining() % 60;

		FString TimeString = FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds);
		FText Time = FText::FromString(TimeString);
		RoundTimeText->SetText(Time);
	}
}

void UGameOwerWidget::OnResenLevel()
{
	const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this);
	UGameplayStatics::OpenLevel(this, FName(CurrentLevelName));
}
