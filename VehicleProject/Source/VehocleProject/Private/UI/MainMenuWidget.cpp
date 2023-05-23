// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Menu/MenuGameModeBase.h"

void UMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (StartGameButton)
	{
		StartGameButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnStartGame);
	}
}



void UMainMenuWidget::OnStartGame()
{
	const FName StartupLevelName = "Untitled";
	UGameplayStatics::OpenLevel(this, StartupLevelName);
}
