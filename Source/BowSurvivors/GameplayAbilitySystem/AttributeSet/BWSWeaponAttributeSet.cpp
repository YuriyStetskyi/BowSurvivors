// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/AttributeSet/BWSWeaponAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"
#include "AbilitySystemBlueprintLibrary.h"

UBWSWeaponAttributeSet::UBWSWeaponAttributeSet(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UBWSWeaponAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);

}

void UBWSWeaponAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

}
