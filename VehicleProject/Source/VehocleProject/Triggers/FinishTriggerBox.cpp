// Fill out your copyright notice in the Description page of Project Settings.


#include "FinishTriggerBox.h"
#include "CHGameModeBase.h"
#include "Menu/MenuGameModeBase.h"
#include "VehocleProject/Character/C_CH_CarBase.h"

void AFinishTriggerBox::BeginPlay()
{
	Super::BeginPlay();
}

AFinishTriggerBox::AFinishTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AFinishTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AFinishTriggerBox::OnOverlapEnd);
}

void AFinishTriggerBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this))
	{
		ACHGameModeBase* CHGameModeBase = Cast<ACHGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
		
		if (CHGameModeBase)
		{			
			CHGameModeBase->InRoad = true;

			if (CHGameModeBase->RoundCount <= 1) {
				CHGameModeBase->SetMatchState(EMatchState::GameOwer);
			}
		}
	}
}

void AFinishTriggerBox::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this))
	{
		ACHGameModeBase* CHGameModeBase = Cast<ACHGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
		if (CHGameModeBase)
		{
			CHGameModeBase->RoundCount--;
		}
	}
}