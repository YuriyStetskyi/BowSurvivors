// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Core/BWSPlayerState.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AttributeSet/BWSCharacterAttributeSet.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"

ABWSPlayerState::ABWSPlayerState()
{
    InitializeComponents();
}

UAbilitySystemComponent* ABWSPlayerState::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

void ABWSPlayerState::InitializeComponents()
{
    AbilitySystemComponent = CreateDefaultSubobject<UBWSAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AttributeSet = CreateDefaultSubobject<UBWSCharacterAttributeSet>(TEXT("AttributeSet"));
}
