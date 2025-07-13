// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Controllers/Player/BWSPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "Characters/BWSPlayerCharacter.h"

ABWSPlayerController::ABWSPlayerController(const FObjectInitializer& ObjectInitializer)
{

}

void ABWSPlayerController::BeginPlay()
{
    //SetupEnhancedInput();
    UE_LOG(LogTemp, Warning, TEXT("Pawn class: %s"), *GetPawn()->GetClass()->GetName());
}

void ABWSPlayerController::OnPossess(APawn* ControlledPawn)
{
    Super::OnPossess(ControlledPawn);

    SetupEnhancedInput();
    SetupInputActions(ControlledPawn);
}

void ABWSPlayerController::SetupEnhancedInput()
{
    if (!IsLocalController() || !DefaultMappingContext) return;

    ULocalPlayer* const LocalPlayer = GetLocalPlayer();
    if (!LocalPlayer) return;

    UEnhancedInputLocalPlayerSubsystem* const InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
    if (!InputSubsystem) return;

    InputSubsystem->ClearAllMappings();
    InputSubsystem->AddMappingContext(DefaultMappingContext, InputPriority);
}

void ABWSPlayerController::SetupInputActions(APawn* ControlledPawn)
{
    PlayerCharacter = Cast<ABWSPlayerCharacter>(ControlledPawn);
    if (!PlayerCharacter) return;

    EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerCharacter->InputComponent);
    if (!EnhancedInputComponent) return;

    EnhancedInputComponent->BindAction(ActionMove, ETriggerEvent::Triggered, PlayerCharacter, &ABWSPlayerCharacter::Move);
    EnhancedInputComponent->BindAction(ActionMove, ETriggerEvent::Triggered, PlayerCharacter, &ABWSPlayerCharacter::Shoot);
}
