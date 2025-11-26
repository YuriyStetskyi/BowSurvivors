// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "BWSMMCUtilityScore.generated.h"

/**
 *  Magnitude Modifier Calculation for Utility Score
 */
UCLASS()
class BOWSURVIVORS_API UBWSMMCUtilityScore : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
    UBWSMMCUtilityScore(const FObjectInitializer& ObjectInitializer);

    /* Main method that returns result of MMC. */
    virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:

    /* Range Definition */
    FGameplayEffectAttributeCaptureDefinition RangeDef;

    /* Speed Definition */
    FGameplayEffectAttributeCaptureDefinition SpeedDef;

    /* Size Definition */
    FGameplayEffectAttributeCaptureDefinition SizeDef;

};
