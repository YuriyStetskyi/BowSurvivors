// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "BWSAbilitySystemComponent.generated.h"

class UGameplayAbility;

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer& /* AssetTags */);

/**
 *  Main GAS class. Every actor that is supposed to interact with GAS should have this class.
 */
UCLASS()
class BOWSURVIVORS_API UBWSAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
    /* Should be called after AbilityActorInfo was set. */
    void AbilityActorInfoSet();
   
    /* Delegate that runs when you want to apply gameplay effects to self. */
    FEffectAssetTags EffectAssetTags;

    /* Adds array of abilities to character that uses current ASC */
    void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities);

    /* Function that runs when input tied to tag thats tied to ability is HELD */
    void AbilityInputTagHeld(const FGameplayTag& InputTag);
    /* Function that runs when input tied to tag thats tied to ability is RELEASED */
    void AbilityInputTagReleased(const FGameplayTag& InputTag);

protected:
    /* Function that runs when gameplay effect is applied to self. */
    void OnGameplayEffectAppliedToSelf(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);


private:


};
