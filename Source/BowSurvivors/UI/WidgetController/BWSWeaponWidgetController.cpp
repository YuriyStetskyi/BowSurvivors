// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "UI/WidgetController/BWSWeaponWidgetController.h"
#include "GameplayAbilitySystem/AttributeSet/BWSWeaponAttributeSet.h"
#include "GameplayAbilitySystem/Data/BWSWeaponAttributeInfo.h"
#include "BWSGameplayTags.h"

void UBWSWeaponWidgetController::BroadcastInitialValues()
{
    UBWSWeaponAttributeSet* const WeaponAS = Cast<UBWSWeaponAttributeSet>(AttributeSet);
    if (!WeaponAS) return;

    check(WeaponAttributeInfo);

    FWeaponAttributeInfo Info = WeaponAttributeInfo->FindAttributeInfoForTag(FBWSGameplayTags::Get().Attributes_Weapon_Power_Damage);
    Info.AttributeValue = WeaponAS->GetDamage();
    OnWeaponAttributeChanged.Broadcast(Info);
}

void UBWSWeaponWidgetController::BindCallbacksToDependencies()
{

}
