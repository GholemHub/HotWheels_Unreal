// Fill out your copyright notice in the Description page of Project Settings.


#include "CH_TimerCharacter.h"

// Sets default values
ACH_TimerCharacter::ACH_TimerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACH_TimerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ACH_TimerCharacter::CountDown, 1.f, true, 0.0 );

}

// Called every frame
void ACH_TimerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACH_TimerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACH_TimerCharacter::CountDown()
{
	if (Seconds != 0) 
	{
		Seconds = Seconds - 1;
	}
	else
	{
		if (Minutes == 0)
		{

		}
		else
		{
			Minutes = Minutes - 1;
			Seconds = 59;
		}
	}
}

