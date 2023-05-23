#include "UI/SettingsWidget.h"
#include "Components/Button.h"
#include "Components/SpinBox.h"
#include "Kismet/GameplayStatics.h"
#include "Menu/MenuGameModeBase.h"


void USettingsWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (CountOfRounds1)
	{
		CountOfRounds1->OnClicked.AddDynamic(this, &USettingsWidget::OnCountOfRounds1);
	}
	if (CountOfRounds2)
	{
		CountOfRounds2->OnClicked.AddDynamic(this, &USettingsWidget::OnCountOfRounds2);
	}
	if (CountOfRounds3)
	{
		CountOfRounds3->OnClicked.AddDynamic(this, &USettingsWidget::OnCountOfRounds3);
	}
	if (StartButton)
	{
		StartButton->OnClicked.AddDynamic(this, &USettingsWidget::OnStartButton);
	}
	if (MaxTimeCountSpinBox)
	{
		MaxTimeCountSpinBox->OnValueChanged.AddDynamic(this, &USettingsWidget::OnMaxTimeSpinBox);
	}
}

void USettingsWidget::OnCountOfRounds1()
{
	ACHGameModeBase* GameMode = Cast<ACHGameModeBase>(UGameplayStatics::GetGameMode(this));
	if (GameMode)
	{
		GameMode->RoundCount = 2;
	}
}

void USettingsWidget::OnCountOfRounds2()
{
	ACHGameModeBase* GameMode = Cast<ACHGameModeBase>(UGameplayStatics::GetGameMode(this));
	if (GameMode)
	{
		GameMode->RoundCount = 3;
	}
}

void USettingsWidget::OnCountOfRounds3()
{
	ACHGameModeBase* GameMode = Cast<ACHGameModeBase>(UGameplayStatics::GetGameMode(this));

	if (GameMode)
	{
		GameMode->RoundCount = 4;
	}
}

void USettingsWidget::OnStartButton()
{
	ACHGameModeBase* GameMode = Cast<ACHGameModeBase>(UGameplayStatics::GetGameMode(this));
	if (GameMode)
	{
		if (GameMode->RoundCount == 0)
		{
			GameMode->RoundCount = 2;
			GameMode->SetMatchState(EMatchState::InProgress);
		}
		else
		{
			GameMode->SetMatchState(EMatchState::InProgress);
		}
	}
}

void USettingsWidget::OnMaxTimeSpinBox(float NewValue)
{
	ACHGameModeBase* GameMode = Cast<ACHGameModeBase>(UGameplayStatics::GetGameMode(this));
	if (GameMode)
	{
		GameMode->MaxTimeCount = NewValue;
	}
}

