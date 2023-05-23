// Fill out your copyright notice in the Description page of Project Settings.
#include "CHGameModeBase.h"
#include "Menu/MenuGameModeBase.h"
#include "VehocleProject/Character/C_CH_CarBase.h"

void ACHGameModeBase::StartPlay()
{
    Super::StartPlay();

    RoundCountDown = 0;
    GetWorldTimerManager().SetTimer(TimerHandle, this, &ACHGameModeBase::TimeUpdate, 1.0f, true);
    SetMatchState(EMatchState::Settings);
}

void ACHGameModeBase::MigrateRoundCount(AMenuGameModeBase* MenuGameMode)
{
    if (MenuGameMode)
    {
        RoundCount = MenuGameMode->RoundCount;
    }
}

void ACHGameModeBase::TimeUpdate()
{
    if (InRoad)
    {
        if (++RoundCountDown == MaxTimeCount)
        {
            SetMatchState(EMatchState::GameOwer);
            GetWorldTimerManager().ClearTimer(TimerHandle);
        }
    }
}

void ACHGameModeBase::SetMatchState(EMatchState State)
{
    if (MatchState == State)
    {
        return;
    }

    MatchState = State;
    OnMatchStateChanged.Broadcast(MatchState);
}

bool ACHGameModeBase::SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate)
{
    const bool PauseSet = Super::SetPause(PC, CanUnpauseDelegate);
    if (PauseSet)
    {
        SetMatchState(EMatchState::Pause);
    }
    return PauseSet;
}

bool ACHGameModeBase::ClearPause()
{
    const bool PauseSet = Super::ClearPause();
    if (PauseSet)
    {
        SetMatchState(EMatchState::InProgress);
    }
    return PauseSet;
}
