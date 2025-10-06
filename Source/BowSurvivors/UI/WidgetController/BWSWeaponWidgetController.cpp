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

    for (TPair<FGameplayTag, TStaticFuncPtr<FGameplayAttribute()>> Pair : WeaponAS->TagsToAttributes)
    {
        FWeaponAttributeInfo Info = WeaponAttributeInfo->FindAttributeInfoForTag(Pair.Key);
        Info.AttributeValue = Pair.Value().GetNumericValue(WeaponAS);
        OnWeaponAttributeChanged.Broadcast(Info);
    }
}

void UBWSWeaponWidgetController::BindCallbacksToDependencies()
{

}
