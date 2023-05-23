// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VehocleProject/Character/C_CH_CarBase.h"
#include "CHGameModeBase.h"
#include "GameOwerWidget.generated.h"


class UButton;
class UTextBlock;
/**
 * 
 */
UCLASS()
class VEHOCLEPROJECT_API UGameOwerWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetroundTime(const FText& Time);
protected:
	UPROPERTY(meta = (BindWidget))
		UButton* ResetLevelButton;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* RoundTimeText;

	virtual void NativeOnInitialized() override;
private:

	void OnMatchStateChanged(EMatchState State);
	
	UFUNCTION()
		void OnResenLevel();
public:
	UFUNCTION(BlueprintCallable, Category = "UI")
		int32 GetRoundSecondsRemaining() const;

private:
	ACHGameModeBase* CHGameModeBase() const;
};
