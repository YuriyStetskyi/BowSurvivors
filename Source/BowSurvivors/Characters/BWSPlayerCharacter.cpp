// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Characters/BWSPlayerCharacter.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/BWSWeaponComponent.h"
#include "Core/BWSPlayerState.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"
#include "Controllers/Player/BWSPlayerController.h"
#include "UI/HUD/BWSHUD.h"

ABWSPlayerCharacter::ABWSPlayerCharacter(const FObjectInitializer& ObjectInitializer)
    : SpringArmComponent(nullptr)
    , CameraComponent(nullptr)
    , WeaponComponent(nullptr)
{
    InitializeComponents();
}

void ABWSPlayerCharacter::Move(const FInputActionValue& InputActionValue)
{
    const FVector2D MovementVector = InputActionValue.Get<FVector2D>();

    AddMovementInput(FVector::ForwardVector, MovementVector.Y);
    AddMovementInput(FVector::RightVector, MovementVector.X);
}

void ABWSPlayerCharacter::Shoot(const FInputActionValue& InputActionValue)
{
    WeaponComponent->Attack();
}

void ABWSPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ABWSPlayerCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    InitializeAbilitySystemInfo();
}

void ABWSPlayerCharacter::InitializeComponents()
{
    /*
        Thing to remember:
        Default Root - CapsuleComponent (default component)
        SkeletalMesh - you can get via GetMesh(). Is attached to Root by default.
    */

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
    SpringArmComponent->SetupAttachment(GetRootComponent());

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    CameraComponent->SetupAttachment(SpringArmComponent);

    WeaponComponent = CreateDefaultSubobject<UBWSWeaponComponent>(TEXT("WeaponComponent"));
}

void ABWSPlayerCharacter::InitializeAbilitySystemInfo()
{
    ABWSPlayerState* const BWSPlayerState = GetPlayerState<ABWSPlayerState>();
    if (!BWSPlayerState) return;
    
    UAbilitySystemComponent* const ASC = BWSPlayerState->GetAbilitySystemComponent();
    if (!ASC) return;

    ASC->InitAbilityActorInfo(BWSPlayerState, this);
    AbilitySystemComponent = BWSPlayerState->GetAbilitySystemComponent();
    AttributeSet = BWSPlayerState->GetAttributeSet();

    ABWSPlayerController* const BWSPlayerController = Cast<ABWSPlayerController>(GetController());
    if (!BWSPlayerController) return;

    ABWSHUD* const HUD = Cast<ABWSHUD>(BWSPlayerController->GetHUD());
    if (!HUD) return;

    HUD->InitOverlay(BWSPlayerController, BWSPlayerState, AbilitySystemComponent, AttributeSet);
}
