// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "BWSMMCWeaponScore.generated.h"

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSMMCWeaponScore : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
    UBWSMMCWeaponScore(const FObjectInitializer& ObjectInitializer);

    virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:

    FGameplayEffectAttributeCaptureDefinition DPSDef;
    FGameplayEffectAttributeCaptureDefinition UtilityScoreDef;
};
