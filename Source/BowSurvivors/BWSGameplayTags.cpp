// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "BWSGameplayTags.h"
#include "GameplayTagsManager.h"

FBWSGameplayTags FBWSGameplayTags::GameplayTags;

void FBWSGameplayTags::InitializeNativeGameplayTags()
{
    GameplayTags.Attributes_Weapon_Power_Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Power.Damage"), FString("Amount of health removed from target when 1 projectile hits once"));
    GameplayTags.Attributes_Weapon_Power_FireRate = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Power.FireRate"), FString("Time passed between every shot"));
    GameplayTags.Attributes_Weapon_Power_Projectiles = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Power.Projectiles"), FString("Amount of projectiles shot per each shot instance"));
    GameplayTags.Attributes_Weapon_Effectiveness_Range = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Effectiveness.Range"), FString("Distance projectile travels before disappearing"));
    GameplayTags.Attributes_Weapon_Effectiveness_Speed = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Effectiveness.Speed"), FString("Units per second projectiles travel at"));
    GameplayTags.Attributes_Weapon_Effectiveness_Size = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Effectiveness.Size"), FString("Size multiplier of a projectile"));
    GameplayTags.Attributes_Weapon_DPS = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.DPS"), FString("Damage * Firerate * Projectiles"));
    GameplayTags.Attributes_Weapon_Utility = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Utility"), FString("Range * Speed * Size"));
    GameplayTags.Attributes_Weapon_Score = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Score"), FString("DPS + Utility"));

}
 