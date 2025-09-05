// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/ModMagCalc/BWSMMCWeaponScore.h"
#include "GameplayAbilitySystem/AttributeSet/BWSWeaponAttributeSet.h"
#include "Interaction/BWSCombatInterface.h"

UBWSMMCWeaponScore::UBWSMMCWeaponScore(const FObjectInitializer& ObjectInitializer)
{
    DPSDef.AttributeToCapture = UBWSWeaponAttributeSet::GetDPSAttribute();
    DPSDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
    DPSDef.bSnapshot = false;

    UtilityScoreDef.AttributeToCapture = UBWSWeaponAttributeSet::GetUtilityScoreAttribute();
    UtilityScoreDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
    UtilityScoreDef.bSnapshot = false;

    RelevantAttributesToCapture.Add(DPSDef);
    RelevantAttributesToCapture.Add(UtilityScoreDef);
}

float UBWSMMCWeaponScore::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
    const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
    const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

    FAggregatorEvaluateParameters EvaluationParameters;
    EvaluationParameters.SourceTags = SourceTags;
    EvaluationParameters.TargetTags = TargetTags;

    float DPS = 0.0f;
    GetCapturedAttributeMagnitude(DPSDef, Spec, EvaluationParameters, DPS);

    float UtilityScore = 0.0f;
    GetCapturedAttributeMagnitude(UtilityScoreDef, Spec, EvaluationParameters, UtilityScore);

    float WeaponScore = DPS + UtilityScore;
    return WeaponScore;
}
