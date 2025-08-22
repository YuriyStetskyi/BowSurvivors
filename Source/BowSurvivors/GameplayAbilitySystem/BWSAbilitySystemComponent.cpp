// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"

void UBWSAbilitySystemComponent::AbilityActorInfoSet()
{
    OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UBWSAbilitySystemComponent::OnGameplayEffectAppliedToSelf);
}

void UBWSAbilitySystemComponent::OnGameplayEffectAppliedToSelf(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
    FGameplayTagContainer TagsContainer;
    EffectSpec.GetAllAssetTags(TagsContainer);

    EffectAssetTags.Broadcast(TagsContainer);
}
