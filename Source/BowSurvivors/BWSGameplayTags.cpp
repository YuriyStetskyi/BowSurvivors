// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "BWSGameplayTags.h"
#include "GameplayTagsManager.h"

FBWSGameplayTags FBWSGameplayTags::GameplayTags;

void FBWSGameplayTags::InitializeNativeGameplayTags()
{
    // Initializing Character Attribute Tags

    GameplayTags.Attributes_Character_Combat_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Character.Combat.Health"), FString("Amount of hit points needed to kill character"));
    GameplayTags.Attributes_Character_Combat_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Character.Combat.MaxHealth"), FString("Maximum amount of health character can store"));
    GameplayTags.Attributes_Character_Combat_MovementSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Character.Combat.MovementSpeed"), FString("Units per second character is moving at"));
    GameplayTags.Attributes_Character_Combat_Dashes = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Character.Combat.Dashes"), FString("Current number of dashes character has stored and can use"));
    GameplayTags.Attributes_Character_Combat_MaxDashes = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Character.Combat.MaxDashes"), FString("Maximum number of dashes character can store"));

    GameplayTags.Attributes_Character_Economy_EXP = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Character.Economy.EXP"), FString("Current experience gained"));
    GameplayTags.Attributes_Character_Economy_NextLvlEXP = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Character.Economy.NextLvlEXP"), FString("Experience needed to get next level up"));
    GameplayTags.Attributes_Character_Economy_Gold = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Character.Economy.Gold"), FString("Current gold stored"));


    // Initializing Weapon Attribute Tags
    GameplayTags.Attributes_Weapon_Power_Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Power.Damage"), FString("Amount of health removed from target when 1 projectile hits once"));
    GameplayTags.Attributes_Weapon_Power_FireRate = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Power.FireRate"), FString("Time passed between every shot"));
    GameplayTags.Attributes_Weapon_Power_Projectiles = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Power.Projectiles"), FString("Amount of projectiles shot per each shot instance"));
    GameplayTags.Attributes_Weapon_Effectiveness_Range = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Effectiveness.Range"), FString("Distance projectile travels before disappearing"));
    GameplayTags.Attributes_Weapon_Effectiveness_Speed = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Effectiveness.Speed"), FString("Units per second projectiles travel at"));
    GameplayTags.Attributes_Weapon_Effectiveness_Size = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Effectiveness.Size"), FString("Size multiplier of a projectile"));
    
    GameplayTags.Attributes_Weapon_DPS = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.DPS"), FString("Damage * Firerate * Projectiles"));
    GameplayTags.Attributes_Weapon_Utility = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Utility"), FString("Range * Speed * Size"));
    GameplayTags.Attributes_Weapon_Score = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Score"), FString("DPS + Utility"));

    // Initializing Input Tags
    GameplayTags.InputTag_Attack = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Attack"), FString("Input Tag for Attack action"));
    GameplayTags.InputTag_Ability1 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Ability1"), FString("Input Tag for First Ability action"));
    GameplayTags.InputTag_Ability2 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Ability2"), FString("Input Tag for Second Ability action"));
    GameplayTags.InputTag_Ability3 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Ability3"), FString("Input Tag for Third Ability action"));
    GameplayTags.InputTag_Dash = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Dash"), FString("Input Tag for Dash ability"));

    GameplayTags.InputTag_Interact = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.Interact"), FString("Input Tag for Interact action"));
    GameplayTags.InputTag_ShowStats = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.ShowStats"), FString("Input Tag for Showing Stats action"));
}
 