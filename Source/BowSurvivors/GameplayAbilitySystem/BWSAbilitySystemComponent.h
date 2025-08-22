// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "BWSAbilitySystemComponent.generated.h"

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

protected:
    void OnGameplayEffectAppliedToSelf(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);


private:


};
