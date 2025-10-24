// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayTagContainer.h"
#include "BWSGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:


    UPROPERTY(EditDefaultsOnly, Category = "Input")
    FGameplayTag StartupGameplayTag;
};
