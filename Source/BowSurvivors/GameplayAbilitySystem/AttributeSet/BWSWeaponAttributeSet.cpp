// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/AttributeSet/BWSWeaponAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "BWSGameplayTags.h"

UBWSWeaponAttributeSet::UBWSWeaponAttributeSet(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    FBWSGameplayTags Tags = FBWSGameplayTags::Get();

    TagsToAttributes.Add(Tags.Attributes_Weapon_Power_Damage, GetDamageAttribute);
    TagsToAttributes.Add(Tags.Attributes_Weapon_Power_FireRate, GetFireRateAttribute);
    TagsToAttributes.Add(Tags.Attributes_Weapon_Power_Projectiles, GetProjectilesCountAttribute);
    TagsToAttributes.Add(Tags.Attributes_Weapon_Effectiveness_Range, GetRangeAttribute);
    TagsToAttributes.Add(Tags.Attributes_Weapon_Effectiveness_Speed, GetSpeedAttribute);
    TagsToAttributes.Add(Tags.Attributes_Weapon_Effectiveness_Size, GetSizeAttribute);
}

void UBWSWeaponAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);

}

void UBWSWeaponAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

}
