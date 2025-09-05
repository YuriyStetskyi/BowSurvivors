// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/ModMagCalc/BWSMMCUtilityScore.h"
#include "GameplayAbilitySystem/AttributeSet/BWSWeaponAttributeSet.h"
#include "Interaction/BWSCombatInterface.h"

UBWSMMCUtilityScore::UBWSMMCUtilityScore(const FObjectInitializer& ObjectInitializer)
{
    RangeDef.AttributeToCapture = UBWSWeaponAttributeSet::GetRangeAttribute();
    RangeDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target; 
    RangeDef.bSnapshot = false;

    SpeedDef.AttributeToCapture = UBWSWeaponAttributeSet::GetSpeedAttribute();
    SpeedDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
    SpeedDef.bSnapshot = false;

    SizeDef.AttributeToCapture = UBWSWeaponAttributeSet::GetSizeAttribute();
    SizeDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
    SizeDef.bSnapshot = false;

    RelevantAttributesToCapture.Add(RangeDef);
    RelevantAttributesToCapture.Add(SpeedDef);
    RelevantAttributesToCapture.Add(SizeDef);
}

float UBWSMMCUtilityScore::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
    const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
    const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

    FAggregatorEvaluateParameters EvaluationParameters;
    EvaluationParameters.SourceTags = SourceTags;
    EvaluationParameters.TargetTags = TargetTags;

    float Range = 0.0f;
    GetCapturedAttributeMagnitude(RangeDef, Spec, EvaluationParameters, Range);

    float Speed = 0.0f;
    GetCapturedAttributeMagnitude(SpeedDef, Spec, EvaluationParameters, Speed);

    float Size = 0.0f;
    GetCapturedAttributeMagnitude(SizeDef, Spec, EvaluationParameters, Size);

    float UtilityScore = (Range + Speed) * Size;
    return UtilityScore;
}
