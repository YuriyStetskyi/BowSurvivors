// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Characters/BWSPlayerCharacter.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/BWSWeaponComponent.h"
#include "Core/BWSPlayerState.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AttributeSet/BWSCharacterAttributeSet.h"
#include "GameplayAbilitySystem/AttributeSet/BWSWeaponAttributeSet.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"
#include "Controllers/Player/BWSPlayerController.h"
#include "UI/HUD/BWSHUD.h"
#include "Weapons/BWSBaseWeapon.h"

ABWSPlayerCharacter::ABWSPlayerCharacter(const FObjectInitializer& ObjectInitializer)
    : SpringArmComponent(nullptr)
    , CameraComponent(nullptr)
    , WeaponComponent(nullptr)
{
    InitializeComponents();
}

FVector ABWSPlayerCharacter::GetWeaponSocketLocation(FName SocketName)
{
    if (!WeaponComponent) return FVector();

    ABWSBaseWeapon* const CurrentWeapon = WeaponComponent->GetCurrentWeapon();
    if (!CurrentWeapon) return FVector();

    return CurrentWeapon->GetWeaponSocketLocation(ProjectileStartSocketName);
}

void ABWSPlayerCharacter::Move(const FInputActionValue& InputActionValue)
{
    const FVector2D MovementVector = InputActionValue.Get<FVector2D>();

    AddMovementInput(FVector::ForwardVector, MovementVector.Y);
    AddMovementInput(FVector::RightVector, MovementVector.X);
}

int32 ABWSPlayerCharacter::GetCurrentLevel()
{
    ABWSPlayerState* const BWSPlayerState = GetPlayerState<ABWSPlayerState>();
    if (!BWSPlayerState) return 0;

    return BWSPlayerState->GetCurrentLevel();
}

void ABWSPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ABWSPlayerCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    ABWSPlayerState* const BWSPlayerState = GetPlayerState<ABWSPlayerState>();
    if (!BWSPlayerState) return;

    InitializeAbilityActorInfo();

    AbilitySystemComponent = BWSPlayerState->GetAbilitySystemComponent();
    AttributeSet = BWSPlayerState->GetAttributeSet();

    InitializeOverlay(BWSPlayerState);
    InitializeDefaultAttributes();
    AddCharacterAbilities();
}

void ABWSPlayerCharacter::InitializeComponents()
{
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
    SpringArmComponent->SetupAttachment(GetRootComponent());

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    CameraComponent->SetupAttachment(SpringArmComponent);

    WeaponComponent = CreateDefaultSubobject<UBWSWeaponComponent>(TEXT("WeaponComponent"));
}

void ABWSPlayerCharacter::InitializeOverlay(ABWSPlayerState* const BWSPlayerState)
{
    ABWSPlayerController* const BWSPlayerController = Cast<ABWSPlayerController>(GetController());
    if (!BWSPlayerController) return;

    ABWSHUD* const HUD = Cast<ABWSHUD>(BWSPlayerController->GetHUD());
    if (!HUD) return;

    HUD->InitOverlay(BWSPlayerController, BWSPlayerState, AbilitySystemComponent, AttributeSet);
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
}
