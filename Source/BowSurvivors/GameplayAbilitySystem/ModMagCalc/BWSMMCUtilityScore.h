// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "BWSMMCUtilityScore.generated.h"

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSMMCUtilityScore : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
    UBWSMMCUtilityScore(const FObjectInitializer& ObjectInitializer);

    virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:

    FGameplayEffectAttributeCaptureDefinition RangeDef;
    FGameplayEffectAttributeCaptureDefinition SpeedDef;
    FGameplayEffectAttributeCaptureDefinition SizeDef;

};
