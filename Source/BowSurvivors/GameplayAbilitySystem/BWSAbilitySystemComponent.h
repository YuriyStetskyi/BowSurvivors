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

    void AbilityActorInfoSet();
   
    FEffectAssetTags EffectAssetTags;

    void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities);

    void AbilityInputTagHeld(const FGameplayTag& InputTag);
    void AbilityInputTagReleased(const FGameplayTag& InputTag);

protected:
    void OnGameplayEffectAppliedToSelf(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);


private:


};
