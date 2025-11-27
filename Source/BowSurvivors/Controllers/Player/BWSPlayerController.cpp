// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Controllers/Player/BWSPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "InputAction.h"
#include "Characters/BWSPlayerCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Input/BWSInputConfig.h"
#include "Input/BWSInputComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

#define PROJECTION_RAY_LENGTH 10000.0f

ABWSPlayerController::ABWSPlayerController(const FObjectInitializer& ObjectInitializer)
    :CursorProjectionChannel(ECollisionChannel::ECC_Visibility)
{

}

void ABWSPlayerController::BeginPlay()
{
    Super::BeginPlay();

    SetupCursor();
}

void ABWSPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    UpdateCurrrentMouseLocation();
    LookAtLocation(CurrentMouseLocation);
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
    ABWSPlayerCharacter* const PlayerCharacter = Cast<ABWSPlayerCharacter>(ControlledPawn);
    if (!PlayerCharacter) return;

    BWSInputComponent = Cast<UBWSInputComponent>(PlayerCharacter->InputComponent);
    if (!BWSInputComponent) return;

    BWSInputComponent->BindAction(ActionMove, ETriggerEvent::Triggered, PlayerCharacter, &ABWSPlayerCharacter::Move);
    BWSInputComponent->BindAction(ActionShowWeaponStats, ETriggerEvent::Triggered, this, &ABWSPlayerController::ShowWeaponStats);

    BWSInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
}

void ABWSPlayerController::SetupCursor()
{
    bShowMouseCursor = true;
    FInputModeGameAndUI InputMode;
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
    InputMode.SetHideCursorDuringCapture(false);
    SetInputMode(InputMode);
    SetMouseCursorWidget(EMouseCursor::Type::Crosshairs, CrosshairWidget);
    CurrentMouseCursor = EMouseCursor::Type::Crosshairs;
}

void ABWSPlayerController::ShowWeaponStats()
{
    // Currently only UI animation played, which is executed in BP.
    OnWeaponStatsShow.Broadcast();
}

void ABWSPlayerController::LookAtLocation(const FVector& LocationToLookAt)
{
    APawn* const ControlledPawn = GetPawn();
    if (!ControlledPawn) return;

    FVector CharacterLocation = ControlledPawn->GetActorLocation();

    FVector Start(CharacterLocation.X, CharacterLocation.Y, 0);
    FVector End(LocationToLookAt.X, LocationToLookAt.Y, 0);

    FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Start, End);

    ControlledPawn->SetActorRotation(LookAtRotation);
}

void ABWSPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
    //GEngine->AddOnScreenDebugMessage(1, 3.0f, FColor::Red, *InputTag.ToString());
}

void ABWSPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
    if (!GetASC()) return;
    GetASC()->AbilityInputTagReleased(InputTag);
}

void ABWSPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
    if (!GetASC()) return;
    GetASC()->AbilityInputTagHeld(InputTag);
}

void ABWSPlayerController::UpdateCurrrentMouseLocation()
{
    FHitResult Hit;
    GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(CursorProjectionChannel), true, Hit);
    CurrentMouseLocation = Hit.Location;
}

UBWSAbilitySystemComponent* const ABWSPlayerController::GetASC()
{
    if (!BWSAbilitySystemComponent)
    {
        BWSAbilitySystemComponent = Cast<UBWSAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn()));
    }

    return BWSAbilitySystemComponent;
}
