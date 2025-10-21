// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "GameplayAbilitySystem/Abilities/BWSGameplayAbility.h"
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
        UBWSGameplayAbility* const BWSAbility = Cast<UBWSGameplayAbility>(AbilitySpec.Ability);
        if (!BWSAbility) continue;

        AbilitySpec.DynamicAbilityTags.AddTag(BWSAbility->StartupGameplayTag);
        GiveAbility(AbilitySpec);
    }
}

void UBWSAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
    if (!InputTag.IsValid()) return;

    for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
    {
        if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)) continue;
        AbilitySpecInputPressed(AbilitySpec);

        if (!AbilitySpec.IsActive())
        {
            TryActivateAbility(AbilitySpec.Handle);
        }
    }
}

void UBWSAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
    if (!InputTag.IsValid()) return;

    for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
    {
        if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)) continue;
        AbilitySpecInputReleased(AbilitySpec);
    }
}

void UBWSAbilitySystemComponent::OnGameplayEffectAppliedToSelf(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
    FGameplayTagContainer TagsContainer;
    EffectSpec.GetAllAssetTags(TagsContainer);

    EffectAssetTags.Broadcast(TagsContainer);
}
