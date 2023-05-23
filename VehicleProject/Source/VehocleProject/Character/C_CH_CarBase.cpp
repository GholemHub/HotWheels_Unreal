#include "C_CH_CarBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "ChaosVehicleMovementComponent.h"
#include "ChaosWheeledVehicleMovementComponent.h"
#include "Components/AudioComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Gameframework/GameModeBase.h"
#include "CHGameModeBase.h"


AC_CH_CarBase::AC_CH_CarBase()
{
	SpringArmC = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmC->SetupAttachment(RootComponent);
	SpringArmC->TargetArmLength = 700;
	CameraC = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraC->SetupAttachment(SpringArmC);
	EngineSoundC = CreateDefaultSubobject<UAudioComponent>(TEXT("Engine Sound"));
	EngineSoundC->SetupAttachment(GetMesh());

}



void AC_CH_CarBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponetn)
{
	Super::SetupPlayerInputComponent(PlayerInputComponetn);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponetn))
	{
		EnhancedInputComponent->BindAction(MoveFoward, ETriggerEvent::Triggered, this, &AC_CH_CarBase::MoveingFoward);
		EnhancedInputComponent->BindAction(MoveFoward, ETriggerEvent::Completed, this, &AC_CH_CarBase::MoveingFoward);
		
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AC_CH_CarBase::LookingAction);
		
		EnhancedInputComponent->BindAction(MoveLeftRight, ETriggerEvent::Triggered, this, &AC_CH_CarBase::MoveingLR);
		EnhancedInputComponent->BindAction(MoveLeftRight, ETriggerEvent::Completed, this, &AC_CH_CarBase::MoveingLR);
		
		EnhancedInputComponent->BindAction(MoveBackward, ETriggerEvent::Triggered, this, &AC_CH_CarBase::MoveingBackward);
		EnhancedInputComponent->BindAction(MoveBackward, ETriggerEvent::Completed, this, &AC_CH_CarBase::MoveingBackward);

		EnhancedInputComponent->BindAction(BrakeHandle, ETriggerEvent::Triggered, this, &AC_CH_CarBase::BrakeingPressed);
		EnhancedInputComponent->BindAction(BrakeHandle, ETriggerEvent::Completed, this, &AC_CH_CarBase::BrakeingPressed);

		EnhancedInputComponent->BindAction(PauseGame, ETriggerEvent::Triggered, this, &AC_CH_CarBase::PauseingAction);
		
	}
}


void AC_CH_CarBase::Tick(float DeltaSeconds)
{
	UChaosWheeledVehicleMovementComponent* vehicleComponent = Cast<UChaosWheeledVehicleMovementComponent>(GetVehicleMovementComponent());
	if (!vehicleComponent) return;
	
	EngineSoundC->SetFloatParameter(FName("RPM"), vehicleComponent->GetEngineRotationSpeed());
	Timer += DeltaSeconds;
}

void AC_CH_CarBase::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* CarController = Cast<APlayerController>(GetController()))
	{
		CarController->SetInputMode(FInputModeGameOnly());
		CarController->bShowMouseCursor = false;

		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(CarController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(CarMappingContext, 0);
		}
	}
}


void AC_CH_CarBase::MoveingFoward1(float value)
{
		GetVehicleMovementComponent()->SetThrottleInput(value);
}
void AC_CH_CarBase::MoveingFoward(const FInputActionValue& Value)
{
	if (Value.GetMagnitude() != 0.0f)
	{
		GetVehicleMovementComponent()->SetThrottleInput(Value.GetMagnitude());
	}
	else {
		GetVehicleMovementComponent()->SetThrottleInput(Value.GetMagnitude());
	}
}

void AC_CH_CarBase::MoveingBackward(const FInputActionValue& Value)
{
	if (Value.GetMagnitude() != 0.0f)
	{
		GetVehicleMovementComponent()->SetBrakeInput(Value.GetMagnitude());
	}
	else {
		GetVehicleMovementComponent()->SetBrakeInput(Value.GetMagnitude());
	}
}

void AC_CH_CarBase::MoveingLR(const FInputActionValue& Value)
{
	if (Value.GetMagnitude() < 0.0f)
	{
		GetVehicleMovementComponent()->SetSteeringInput(Value.GetMagnitude());
	}
	else {
		GetVehicleMovementComponent()->SetSteeringInput(Value.GetMagnitude());
	}
}

void AC_CH_CarBase::BrakeingPressed(const FInputActionValue& Value)
{
	const bool Currentvalue = Value.Get<bool>();
	if (Currentvalue)
	{
		GetVehicleMovementComponent()->SetHandbrakeInput(Currentvalue);
	}
	else
	{
		GetVehicleMovementComponent()->SetHandbrakeInput(Currentvalue);
	}
}

void AC_CH_CarBase::LookingAction(const FInputActionValue& Value)
{
	const FVector2D Currentvalue = Value.Get<FVector2D>();
	if (GetController())
	{
		AddControllerPitchInput(Currentvalue.Y * -1);
		AddControllerYawInput(Currentvalue.X);
	}
}

void AC_CH_CarBase::PauseingAction(const FInputActionValue& Value)
{
	const bool CurrentValue = Value.Get<bool>();
	if (GetController())
	{
		APlayerController* PlayerController = Cast<APlayerController>(GetController());
		if (CurrentValue == true)
		{
			GetWorld()->GetAuthGameMode()->SetPause(PlayerController);
			PlayerController->SetInputMode(FInputModeGameOnly());
			PlayerController->bShowMouseCursor = true;
		}
	}
}
