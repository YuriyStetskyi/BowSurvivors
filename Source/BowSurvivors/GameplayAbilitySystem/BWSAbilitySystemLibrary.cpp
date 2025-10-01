// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/BWSAbilitySystemLibrary.h"
#include "UI/WidgetController/BWSOverlayWidgetController.h"
#include "UI/WidgetController/BWSWeaponWidgetController.h"
#include "Controllers/Player/BWSPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Core/BWSPlayerState.h"
#include "UI/HUD/BWSHUD.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "Components/BWSWeaponComponent.h"
#include "Characters/BWSPlayerCharacter.h"
#include "Weapons/BWSBaseWeapon.h"

UBWSOverlayWidgetController* UBWSAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
    APlayerController* const PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
    if (!PC) return nullptr;

    ABWSHUD* const BWSHUD = Cast<ABWSHUD>(PC->GetHUD());
    if (!BWSHUD) return nullptr;

    ABWSPlayerState* const PS = PC->GetPlayerState<ABWSPlayerState>();
    if (!PS) return nullptr;

    UAbilitySystemComponent* const ASC = PS->GetAbilitySystemComponent();
    if (!ASC) return nullptr;

    UAttributeSet* const AS = PS->GetAttributeSet();
    if (!AS) return nullptr;

    return BWSHUD->GetOverlayWidgetController(FWidgetControllerParams(PC, PS, ASC, AS));
}

UBWSWeaponWidgetController* UBWSAbilitySystemLibrary::GetWeaponWidgetController(const UObject* WorldContextObject, EWeaponSlot WeaponSlot)
{
    APlayerController* const PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
    if (!PC) return nullptr;

    ABWSHUD* const BWSHUD = Cast<ABWSHUD>(PC->GetHUD());
    if (!BWSHUD) return nullptr;

    ABWSPlayerState* const PS = PC->GetPlayerState<ABWSPlayerState>();
    if (!PS) return nullptr;

    ABWSPlayerCharacter* const PCharacter = Cast<ABWSPlayerCharacter>(PC->GetPawn());
    if (!PCharacter) return nullptr;

    UBWSWeaponComponent* const WComponent = PCharacter->GetWeaponComponent();
    if (!WComponent) return nullptr;

    switch (WeaponSlot)
    {
    case EWeaponSlot::FisrtWeapon:
    {
        ABWSBaseWeapon* Weapon = WComponent->GetWeapon(EWeaponSlot::FisrtWeapon);
        if (!Weapon) return nullptr;

        UAbilitySystemComponent* const WeaponASC = Weapon->GetAbilitySystemComponent();
        if (!WeaponASC) return nullptr;

        UAttributeSet* const WeaponAS = Weapon->GetAttributeSet();
        if (!WeaponAS) return nullptr;

        return BWSHUD->GetWeaponWidgetController(FWidgetControllerParams(PC, PS, WeaponASC, WeaponAS), EWeaponSlot::FisrtWeapon);
    }
    case EWeaponSlot::SecondWeapon:
    {
        ABWSBaseWeapon* Weapon = WComponent->GetWeapon(EWeaponSlot::SecondWeapon);
        if (!Weapon) return nullptr;

        UAbilitySystemComponent* const WeaponASC = Weapon->GetAbilitySystemComponent();
        if (!WeaponASC) return nullptr;

        UAttributeSet* const WeaponAS = Weapon->GetAttributeSet();
        if (!WeaponAS) return nullptr;

        return BWSHUD->GetWeaponWidgetController(FWidgetControllerParams(PC, PS, WeaponASC, WeaponAS), EWeaponSlot::SecondWeapon);
    }
    case EWeaponSlot::ThirdWeaon:
        break;
    case EWeaponSlot::None:
        break;
    default:
        break;
    }

    return nullptr;
}

UBWSWeaponComponent* UBWSAbilitySystemLibrary::GetPlayerWeaponComponnt(const UObject* WorldContextObject)
{
    APlayerController* const PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
    if (!PC) return nullptr;

    ABWSPlayerCharacter* const PCharacter = Cast<ABWSPlayerCharacter>(PC->GetPawn());
    if (!PCharacter) return nullptr;

    UBWSWeaponComponent* const WComponent = PCharacter->GetWeaponComponent();
    return WComponent;
}
