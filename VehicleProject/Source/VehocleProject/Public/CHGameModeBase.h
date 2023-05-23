// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "VehocleProject/Interfaces/IDataMigrationInterface.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "CHGameModeBase.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnMatchStateChangedSignature, EMatchState);

/**
 * 
 */

UENUM(BlueprintType)
enum class EMatchState : uint8
{
	WaitingToStart = 0,
	InProgress,
	Pause,
	GameOwer,
	Settings
};

UCLASS()
class VEHOCLEPROJECT_API ACHGameModeBase : public AGameModeBase, public IDataMigrationInterface
{
	GENERATED_BODY()

public:
	int32 RoundCountDown;
	int32 GetRoundSecondsRemaining() const { return RoundCountDown; }
	
	int32 RoundCount = 0;
	float MaxTimeCount = 300.f;
	bool InRoad = false;

	virtual void MigrateRoundCount(class AMenuGameModeBase* SourceGameMode) override;

	FOnMatchStateChangedSignature OnMatchStateChanged;
	virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;
	virtual bool ClearPause() override;
	
	void SetMatchState(EMatchState State);
protected:
	virtual void StartPlay() override;
	
private:
	EMatchState MatchState = EMatchState::WaitingToStart;
	FTimerHandle TimerHandle;
	void TimeUpdate();
	
};




