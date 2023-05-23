// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PauseWidget.h"
#include "Gameframework/GameModeBase.h"
#include "Components/Button.h"
#include "VehocleProject/Character/C_CH_CarBase.h"

bool UPauseWidget::Initialize() 
{
	const auto InitStatus = Super::Initialize();
	if (ClearPauseButton) 
	{
		ClearPauseButton->OnClicked.AddDynamic(this, &UPauseWidget::OnClearPause);	
	}
	return InitStatus;
}
void UPauseWidget::OnClearPause()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetOwningPlayer());
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;
	PlayerController->SetInputMode(FInputModeGameOnly());
	PlayerController->bShowMouseCursor = false;
	GetWorld()->GetAuthGameMode()->ClearPause();
}