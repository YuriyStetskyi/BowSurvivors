// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/ModMagCalc/BWSMMCDPS.h"
#include "GameplayAbilitySystem/AttributeSet/BWSWeaponAttributeSet.h"
#include "Interaction/BWSCombatInterface.h"

UBWSMMCDPS::UBWSMMCDPS(const FObjectInitializer& ObjectInitializer)
{
    DamageDef.AttributeToCapture = UBWSWeaponAttributeSet::GetDamageAttribute();
    DamageDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
    DamageDef.bSnapshot = false;

    FireRateDef.AttributeToCapture = UBWSWeaponAttributeSet::GetFireRateAttribute();
    FireRateDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
    FireRateDef.bSnapshot = false;

    ProjectilesCountDef.AttributeToCapture = UBWSWeaponAttributeSet::GetProjectilesCountAttribute();
    ProjectilesCountDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
    ProjectilesCountDef.bSnapshot = false;

    RelevantAttributesToCapture.Add(DamageDef);
    RelevantAttributesToCapture.Add(FireRateDef);
    RelevantAttributesToCapture.Add(ProjectilesCountDef);
}

float UBWSMMCDPS::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
    const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
    const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

    FAggregatorEvaluateParameters EvaluationParameters;
    EvaluationParameters.SourceTags = SourceTags;
    EvaluationParameters.TargetTags = TargetTags;

    float Damage = 0.0f;
    GetCapturedAttributeMagnitude(DamageDef, Spec, EvaluationParameters, Damage);

    float FireRate = 0.0f;
    GetCapturedAttributeMagnitude(FireRateDef, Spec, EvaluationParameters, FireRate);

    float ProjectilesCount = 0.0f;
    GetCapturedAttributeMagnitude(ProjectilesCountDef, Spec, EvaluationParameters, ProjectilesCount);
    
    //if we ever need level of actor effect is applied to.
    /*
    IBWSCombatInterface* CombatInterface = Cast<IBWSCombatInterface>(Spec.GetContext().GetSourceObject());
    if (!CombatInterface) return 0.0f;

    CombatInterface->GetCurrentLevel();
    */

    return Damage * FireRate * ProjectilesCount;

}
