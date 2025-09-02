// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/AttributeSet/BWSCharacterAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"
#include "AbilitySystemBlueprintLibrary.h"

UBWSCharacterAttributeSet::UBWSCharacterAttributeSet(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    InitHealth(30.0f);
    InitMaxHealth(100.0f);
    InitMoney(500.0f);
}

void UBWSCharacterAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);

    if (Attribute == GetHealthAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
    }

    if (Attribute == GetMaxHealthAttribute())
    {
        NewValue = FMath::Max(NewValue, 0.0f);
    }

    if (Attribute == GetMoneyAttribute())
    {
        NewValue = FMath::Max(NewValue, 0.0f);
    }
}

void UBWSCharacterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        SetHealth(FMath::Clamp(GetHealth(), 0, GetMaxHealth()));
    }
}
