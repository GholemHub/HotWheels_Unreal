// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameDataWidget.generated.h"

/**
 * 
 */

class ACHGameModeBase;
UCLASS()
class VEHOCLEPROJECT_API UGameDataWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetRoundSecondsRemaining() const;

private:
	ACHGameModeBase* CHGameModeBase() const;
};
