// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "BWSGameplayTags.h"
#include "Abilities/GameplayAbility.h"

void UBWSAbilitySystemComponent::AbilityActorInfoSet()
{
    OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UBWSAbilitySystemComponent::OnGameplayEffectAppliedToSelf);

    const FBWSGameplayTags& GameplayTags = FBWSGameplayTags::Get();
    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, *GameplayTags.Attributes_Weapon_Power_Damage.ToString());
}

void UBWSAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
    for (TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
    {
        FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
        //GiveAbility(AbilitySpec);
        GiveAbilityAndActivateOnce(AbilitySpec);
    }
}

void UBWSAbilitySystemComponent::OnGameplayEffectAppliedToSelf(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
    FGameplayTagContainer TagsContainer;
    EffectSpec.GetAllAssetTags(TagsContainer);

    EffectAssetTags.Broadcast(TagsContainer);
}
