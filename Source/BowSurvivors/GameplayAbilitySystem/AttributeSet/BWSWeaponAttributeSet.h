// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"
#include "BWSWeaponAttributeSet.generated.h"

template<class T>
using TStaticFuncPtr = typename TBaseStaticDelegateInstance<T, FDefaultDelegateUserPolicy>::FFuncPtr;


/**
 * Attribute Set for Weapons Attributes
 */
UCLASS()
class BOWSURVIVORS_API UBWSWeaponAttributeSet : public UBWSAttributeSet
{
	GENERATED_BODY()
	
public:
    UBWSWeaponAttributeSet(const FObjectInitializer& ObjectInitializer);

    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

    /*
     *   Core Weapon Attributes
     */

    /* Amount of health character should lose when damaged by this weapons projectile */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Main | DPS")
    FGameplayAttributeData Damage;
    ATTRIBUTE_ACCESSORS(UBWSWeaponAttributeSet, Damage);

    /* Describes how many times per second weapon should fire */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Main | DPS")
    FGameplayAttributeData FireRate;
    ATTRIBUTE_ACCESSORS(UBWSWeaponAttributeSet, FireRate);

    /* Amount of projectiles shot when Attack() called in a cone */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Main | DPS")
    FGameplayAttributeData ProjectilesCount;
    ATTRIBUTE_ACCESSORS(UBWSWeaponAttributeSet, ProjectilesCount);

    /* Distance projectile should travel before disappearing / falling to ground*/
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Main | Utility")
    FGameplayAttributeData Range;
    ATTRIBUTE_ACCESSORS(UBWSWeaponAttributeSet, Range);

    /* Speed at which projectile travels */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Main | Utility")
    FGameplayAttributeData Speed;
    ATTRIBUTE_ACCESSORS(UBWSWeaponAttributeSet, Speed);

    /* Number by which default projectile scale is multiplied at creation to increase its size */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Main | Utility")
    FGameplayAttributeData Size;
    ATTRIBUTE_ACCESSORS(UBWSWeaponAttributeSet, Size);

    /*
     *   Derived Weapon Attributes
     */

    /* Amount of Damage bow should deal per second (multiple projectiles might make calculation inconsistent) */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Derived")
    FGameplayAttributeData DPS;
    ATTRIBUTE_ACCESSORS(UBWSWeaponAttributeSet, DPS);

    /* Represents how easy it is to hit with projectiles created with weapon */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Derived")
    FGameplayAttributeData UtilityScore;
    ATTRIBUTE_ACCESSORS(UBWSWeaponAttributeSet, UtilityScore);

    /* Represents how effective weapon is at eliminating enemies */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Main | Utility")
    FGameplayAttributeData WeaponScore;
    ATTRIBUTE_ACCESSORS(UBWSWeaponAttributeSet, WeaponScore);

    /* Array linking tags to attributes. */
    TMap<FGameplayTag, TStaticFuncPtr<FGameplayAttribute()>> TagsToAttributes;

};
