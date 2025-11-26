// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "BWSMMCDPS.generated.h"

/**
 *  Magnitude Modifier Calculation for Damage per second
 */
UCLASS()
class BOWSURVIVORS_API UBWSMMCDPS : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
    UBWSMMCDPS(const FObjectInitializer& ObjectInitializer);

    /* Main method that returns result of MMC. */
    virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:

    /* Damage Definition */
    FGameplayEffectAttributeCaptureDefinition DamageDef;
 
    /* FireRate Definition */
    FGameplayEffectAttributeCaptureDefinition FireRateDef;
    
    /* Projectiles Count Definition */
    FGameplayEffectAttributeCaptureDefinition ProjectilesCountDef;

};
