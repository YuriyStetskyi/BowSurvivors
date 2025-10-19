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

    /*
    *   Character Attributes
    */

    FGameplayTag Attributes_Character_Combat_Health;
    FGameplayTag Attributes_Character_Combat_MaxHealth;
    FGameplayTag Attributes_Character_Combat_MovementSpeed;
    FGameplayTag Attributes_Character_Combat_Dashes;
    FGameplayTag Attributes_Character_Combat_MaxDashes;

    FGameplayTag Attributes_Character_Economy_EXP;
    FGameplayTag Attributes_Character_Economy_NextLvlEXP;
    FGameplayTag Attributes_Character_Economy_Gold;

    /*
    *   Weapon Attributes
    */

    FGameplayTag Attributes_Weapon_Power_Damage;
    FGameplayTag Attributes_Weapon_Power_FireRate;
    FGameplayTag Attributes_Weapon_Power_Projectiles;
    FGameplayTag Attributes_Weapon_Effectiveness_Range;
    FGameplayTag Attributes_Weapon_Effectiveness_Speed;
    FGameplayTag Attributes_Weapon_Effectiveness_Size;

    FGameplayTag Attributes_Weapon_DPS;
    FGameplayTag Attributes_Weapon_Utility;
    FGameplayTag Attributes_Weapon_Score;

    /*
    *   Input Tags
    */

    FGameplayTag InputTag_Attack;
    FGameplayTag InputTag_Ability1;
    FGameplayTag InputTag_Ability2;
    FGameplayTag InputTag_Ability3;
    FGameplayTag InputTag_Dash;

    FGameplayTag InputTag_Interact;
    FGameplayTag InputTag_ShowStats;


protected:

private:
    static FBWSGameplayTags GameplayTags;


};