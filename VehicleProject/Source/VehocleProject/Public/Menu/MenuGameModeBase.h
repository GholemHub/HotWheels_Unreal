// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MenuGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class VEHOCLEPROJECT_API AMenuGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AMenuGameModeBase();
	int32 RoundCount;
};
