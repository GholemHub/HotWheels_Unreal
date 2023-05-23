// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "CHGameModeBase.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class VEHOCLEPROJECT_API AGameHUD : public AHUD
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "UI")
		float GetTimer() const;
	
	bool FirstTime = true;
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> WidgetHUDClass = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> WidgetPauseClass = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> WidgetGameOverClass = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> WidgetSettingsClass = nullptr;
		virtual void BeginPlay() override;
private:
	UPROPERTY()
		TMap<EMatchState, UUserWidget*> GameWidgets;
	UPROPERTY()
		UUserWidget* CurrentWidget = nullptr;

	void OnMatchStateChanged(EMatchState);
};
