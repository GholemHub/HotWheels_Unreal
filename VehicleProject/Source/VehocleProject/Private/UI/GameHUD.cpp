#include "UI/GameHUD.h"
#include "CHGameModeBase.h"


float AGameHUD::GetTimer() const
{
	return 0.0f;
}

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();
	
	GameWidgets.Add(EMatchState::InProgress, CreateWidget<UUserWidget>(GetWorld(), WidgetHUDClass));
	GameWidgets.Add(EMatchState::Pause, CreateWidget<UUserWidget>(GetWorld(), WidgetPauseClass));
	GameWidgets.Add(EMatchState::GameOwer, CreateWidget<UUserWidget>(GetWorld(), WidgetGameOverClass));
	GameWidgets.Add(EMatchState::Settings, CreateWidget<UUserWidget>(GetWorld(), WidgetSettingsClass));

	for (auto GameWidgetPair : GameWidgets)
	{
		const auto GameWidget = GameWidgetPair.Value;
		if (!GameWidget) continue;
		GameWidget->AddToViewport();
		GameWidget->SetVisibility(ESlateVisibility::Hidden);
	}

	if (GetWorld())
	{
		const auto GameMode = Cast<ACHGameModeBase>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			GameMode->OnMatchStateChanged.AddUObject(this, &AGameHUD::OnMatchStateChanged);
		}
	}
}

void AGameHUD::OnMatchStateChanged(EMatchState State)
{
	if (CurrentWidget)
	{
		CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
	}
	if (GameWidgets.Contains(State))
	{
		CurrentWidget = GameWidgets[State];
		
		APlayerController* PlayerController = GetOwningPlayerController();
		if (State == EMatchState::Settings) {
			if (FirstTime == true) {
				CurrentWidget->SetVisibility(ESlateVisibility::Visible);
				PlayerController->SetInputMode(FInputModeUIOnly());
				PlayerController->bShowMouseCursor = true;
				FirstTime = !FirstTime;
			}
			else
			{
				CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
				FirstTime = !FirstTime;
			}
		}
		if (State == EMatchState::InProgress)
		{
			CurrentWidget->SetVisibility(ESlateVisibility::Visible);
			PlayerController->SetInputMode(FInputModeGameOnly());
			PlayerController->bShowMouseCursor = false;
		}
		if (State == EMatchState::GameOwer) 
		{
			CurrentWidget->SetVisibility(ESlateVisibility::Visible);
			PlayerController->SetInputMode(FInputModeUIOnly());
			PlayerController->bShowMouseCursor = true;
		}
		if (State == EMatchState::Pause)
		{
			CurrentWidget->SetVisibility(ESlateVisibility::Visible);
			PlayerController->SetInputMode(FInputModeUIOnly());
			PlayerController->bShowMouseCursor = true;
		}
	}
}
