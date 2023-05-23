// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VehocleProject/Character/C_CH_CarBase.h"
#include "CHGameModeBase.h"
#include "MainMenuWidget.generated.h"


class UButton;
/**
 * 
 */
UCLASS()
class VEHOCLEPROJECT_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
		UButton* StartGameButton;

	virtual void NativeOnInitialized() override;
private:

	UFUNCTION()
		void OnStartGame();
};
