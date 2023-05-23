// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CHGameModeBase.h"
#include "SettingsWidget.generated.h"

class UButton;
class USpinBox;

/**
 * 
 */
UCLASS()
class VEHOCLEPROJECT_API USettingsWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
		UButton* CountOfRounds1;
	UPROPERTY(meta = (BindWidget))
		UButton* CountOfRounds2;
	UPROPERTY(meta = (BindWidget))
		UButton* CountOfRounds3;
	UPROPERTY(meta = (BindWidget))
		UButton* StartButton;
	UPROPERTY(meta = (BindWidget))
		USpinBox* MaxTimeCountSpinBox;


	virtual void NativeOnInitialized() override;
private:
	UFUNCTION()
		void OnCountOfRounds1();
	UFUNCTION()
		void OnCountOfRounds2();
	UFUNCTION()
		void OnCountOfRounds3();
	UFUNCTION()
		void OnStartButton();
	UFUNCTION()
		void OnMaxTimeSpinBox(float NewValue);
};
