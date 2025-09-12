// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "BWSGameplayTags.h"
#include "GameplayTagsManager.h"

FBWSGameplayTags FBWSGameplayTags::GameplayTags;

void FBWSGameplayTags::InitializeNativeGameplayTags()
{
    GameplayTags.Attributes_Weapon_Power_Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Weapon.Power.Damage"), FString("Testing native gameplay tag damage"));



}
 