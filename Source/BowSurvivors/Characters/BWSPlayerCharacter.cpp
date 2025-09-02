// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Characters/BWSPlayerCharacter.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/BWSWeaponComponent.h"
#include "Core/BWSPlayerState.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AttributeSet/BWSCharacterAttributeSet.h"
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

/* PURE DEBUG FUNCTION SHOULD BE REMOVED LATER*/
void ABWSPlayerCharacter::Test_TakeDamage(float Damage)
{
    ABWSPlayerState* const PS = Cast<ABWSPlayerState>(GetPlayerState());
    if (!PS) return;

    float CurrentHP = UBWSCharacterAttributeSet::GetHealthAttribute().GetNumericValue(PS->GetAttributeSet());

    PS->GetAbilitySystemComponent()->SetNumericAttributeBase(UBWSCharacterAttributeSet::GetHealthAttribute(), CurrentHP - Damage);
}

void ABWSPlayerCharacter::Test_AddGold(float MoneyToAdd)
{
    ABWSPlayerState* const PS = Cast<ABWSPlayerState>(GetPlayerState());
    if (!PS) return;

    float CurrentMoney = UBWSCharacterAttributeSet::GetMoneyAttribute().GetNumericValue(PS->GetAttributeSet());

    PS->GetAbilitySystemComponent()->SetNumericAttributeBase(UBWSCharacterAttributeSet::GetMoneyAttribute(), CurrentMoney + MoneyToAdd);
}

void ABWSPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ABWSPlayerCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    InitializeAbilityActorInfo();
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

void ABWSPlayerCharacter::InitializeAbilityActorInfo()
{
    ABWSPlayerState* const BWSPlayerState = GetPlayerState<ABWSPlayerState>();
    if (!BWSPlayerState) return;
    
    UAbilitySystemComponent* const GenericASC = BWSPlayerState->GetAbilitySystemComponent();
    if (!GenericASC) return;

    UBWSAbilitySystemComponent* const BWSASC = Cast<UBWSAbilitySystemComponent>(GenericASC);
    if (!BWSASC) return;

    GenericASC->InitAbilityActorInfo(BWSPlayerState, this);
    BWSASC->AbilityActorInfoSet();

    AbilitySystemComponent = BWSPlayerState->GetAbilitySystemComponent();
    AttributeSet = BWSPlayerState->GetAttributeSet();

    ABWSPlayerController* const BWSPlayerController = Cast<ABWSPlayerController>(GetController());
    if (!BWSPlayerController) return;

    ABWSHUD* const HUD = Cast<ABWSHUD>(BWSPlayerController->GetHUD());
    if (!HUD) return;

    HUD->InitOverlay(BWSPlayerController, BWSPlayerState, AbilitySystemComponent, AttributeSet);

    InitializeDefaultAttributes();
}
