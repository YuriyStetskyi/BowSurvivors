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

void ABWSPlayerCharacter::Test_DisplayWeaponStats()
{
    ABWSBaseWeapon* const Weapon = WeaponComponent->GetCurrentWeapon();
    if (!Weapon) return;

    float Damage = UBWSWeaponAttributeSet::GetDamageAttribute().GetNumericValue(Weapon->GetAttributeSet());
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("Damage: %.2f"), Damage));

    float FireRate = UBWSWeaponAttributeSet::GetFireRateAttribute().GetNumericValue(Weapon->GetAttributeSet());
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("FireRate: %.2f"), FireRate));

    float ProjectilesCount = UBWSWeaponAttributeSet::GetProjectilesCountAttribute().GetNumericValue(Weapon->GetAttributeSet());
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("Projectiles Count: %.2f"), ProjectilesCount));

    float Range = UBWSWeaponAttributeSet::GetRangeAttribute().GetNumericValue(Weapon->GetAttributeSet());
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, FString::Printf(TEXT("Range: %.2f"), Range));

    float Speed = UBWSWeaponAttributeSet::GetSpeedAttribute().GetNumericValue(Weapon->GetAttributeSet());
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, FString::Printf(TEXT("Speed: %.2f"), Speed));

    float Size = UBWSWeaponAttributeSet::GetSizeAttribute().GetNumericValue(Weapon->GetAttributeSet());
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, FString::Printf(TEXT("Size: %.2f"), Size));


    float DPS = UBWSWeaponAttributeSet::GetDPSAttribute().GetNumericValue(Weapon->GetAttributeSet());
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("DPS: %.2f"), DPS));

    float UtilityScore = UBWSWeaponAttributeSet::GetUtilityScoreAttribute().GetNumericValue(Weapon->GetAttributeSet());
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("Utility Score: %.2f"), UtilityScore));


    float WeaponScore = UBWSWeaponAttributeSet::GetWeaponScoreAttribute().GetNumericValue(Weapon->GetAttributeSet());
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Orange, FString::Printf(TEXT("Weapon Score: %.2f"), WeaponScore));

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

    InitializeAbilityActorInfo();
    AddCharacterAbilities();
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
