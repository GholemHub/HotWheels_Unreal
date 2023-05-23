#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "InputActionValue.h"
#include "C_CH_CarBase.generated.h"

/**
 * 
 */

class UInputMappingContext;
class UInputAction;

UCLASS()
class VEHOCLEPROJECT_API AC_CH_CarBase : public AWheeledVehiclePawn
{
	GENERATED_BODY()

public:

	AC_CH_CarBase();
	//Components
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class USpringArmComponent* SpringArmC;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UCameraComponent* CameraC;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UAudioComponent* EngineSoundC;
	//Timers
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Minutes = 2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Seconds = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer")
		float Timer;
protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponetn) override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* CarMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveFoward;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
		UInputAction* MoveBackward;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
		UInputAction* MoveLeftRight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
		UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
		UInputAction* BrakeHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
		UInputAction* PauseGame;

private:
	//Movement fun
	void MoveingFoward(const FInputActionValue& Value);
	void MoveingFoward1(float Value);
	void MoveingBackward(const FInputActionValue& Value);
	void MoveingLR(const FInputActionValue& Value);
	void BrakeingPressed(const FInputActionValue& Value);
	//look fun
	void LookingAction(const FInputActionValue& Value);
	//Pause
	void PauseingAction(const FInputActionValue& Value);
};
