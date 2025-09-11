// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "BWSGameplayTags.h"

void UBWSAbilitySystemComponent::AbilityActorInfoSet()
{
    OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UBWSAbilitySystemComponent::OnGameplayEffectAppliedToSelf);

    const FBWSGameplayTags& GameplayTags = FBWSGameplayTags::Get();
    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, *GameplayTags.Attributes_Weapon_Test_Damage.ToString());
}

void UBWSAbilitySystemComponent::OnGameplayEffectAppliedToSelf(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
    FGameplayTagContainer TagsContainer;
    EffectSpec.GetAllAssetTags(TagsContainer);

    EffectAssetTags.Broadcast(TagsContainer);
}
