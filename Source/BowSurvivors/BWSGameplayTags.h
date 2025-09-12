// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * Singleton containing native Gameplay Tags
 */

struct FBWSGameplayTags
{
public:
    static const FBWSGameplayTags& Get() { return GameplayTags; }

    static void InitializeNativeGameplayTags();

    FGameplayTag Attributes_Weapon_Power_Damage;
    FGameplayTag Attributes_Weapon_Power_FireRate;
    FGameplayTag Attributes_Weapon_Power_Projectiles;
    FGameplayTag Attributes_Weapon_Effectiveness_Range;
    FGameplayTag Attributes_Weapon_Effectiveness_Speed;
    FGameplayTag Attributes_Weapon_Effectiveness_Size;

    FGameplayTag Attributes_Weapon_DPS;
    FGameplayTag Attributes_Weapon_Utility;
    FGameplayTag Attributes_Weapon_Score;


protected:

private:
    static FBWSGameplayTags GameplayTags;


};