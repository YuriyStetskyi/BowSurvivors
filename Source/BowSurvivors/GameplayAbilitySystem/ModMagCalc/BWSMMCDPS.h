// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "BWSMMCDPS.generated.h"

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSMMCDPS : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
    UBWSMMCDPS(const FObjectInitializer& ObjectInitializer);

    virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:

    FGameplayEffectAttributeCaptureDefinition DamageDef; //Def - definition
    FGameplayEffectAttributeCaptureDefinition FireRateDef;
    FGameplayEffectAttributeCaptureDefinition ProjectilesCountDef;

};
