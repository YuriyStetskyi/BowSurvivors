// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Controllers/Player/BWSPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "Characters/BWSPlayerCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

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

    CurrentMouseLocation = FindProjectedMouseLocation(CursorProjectionChannel);
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

    EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerCharacter->InputComponent);
    if (!EnhancedInputComponent) return;

    EnhancedInputComponent->BindAction(ActionMove, ETriggerEvent::Triggered, PlayerCharacter, &ABWSPlayerCharacter::Move);
    EnhancedInputComponent->BindAction(ActionShoot, ETriggerEvent::Triggered, PlayerCharacter, &ABWSPlayerCharacter::Shoot);
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

FVector ABWSPlayerController::FindProjectedMouseLocation(ECollisionChannel ProjectionCollisionChannel)
{
    float X = 0;
    float Y = 0;

    if (!GetMousePosition(X, Y)) return FVector::ZeroVector;

    FVector WorldMouseLocation(FVector::ZeroVector);
    FVector WorldMouseDirection(FVector::ZeroVector);

    DeprojectScreenPositionToWorld(X, Y, WorldMouseLocation, WorldMouseDirection);

    FVector Start = WorldMouseLocation;
    FVector End = Start + (WorldMouseDirection * PROJECTION_RAY_LENGTH);

    FHitResult HitResult;
    GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ProjectionCollisionChannel);

    /* Debug */
    //FHitResult DebugHitResult;
    //UKismetSystemLibrary::LineTraceSingle(this, Start, End, UEngineTypes::ConvertToTraceType(CursorProjectionChannel), false, {}, EDrawDebugTrace::ForOneFrame, DebugHitResult, true);

    if (!HitResult.bBlockingHit) return FVector::ZeroVector;

    return HitResult.ImpactPoint;
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
