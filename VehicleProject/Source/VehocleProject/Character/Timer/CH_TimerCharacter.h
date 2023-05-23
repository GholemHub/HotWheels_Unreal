// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CH_TimerCharacter.generated.h"

UCLASS()
class VEHOCLEPROJECT_API ACH_TimerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACH_TimerCharacter();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Minutes = 2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Seconds = 2;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void CountDown();

	

};
