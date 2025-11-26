// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "BWSMMCWeaponScore.generated.h"

/**
 *  Magnitude Modifier Calculation for Weapon Score. DPS and Utility.
 */
UCLASS()
class BOWSURVIVORS_API UBWSMMCWeaponScore : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
    UBWSMMCWeaponScore(const FObjectInitializer& ObjectInitializer);

    /* Main method that returns result of MMC. */
    virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:
    /* DPS Definition */
    FGameplayEffectAttributeCaptureDefinition DPSDef;

    /* Utility Score Definition */
    FGameplayEffectAttributeCaptureDefinition UtilityScoreDef;
};
