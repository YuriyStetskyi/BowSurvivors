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

    FGameplayTag Attributes_Weapon_Test_Damage;
protected:

private:
    static FBWSGameplayTags GameplayTags;


};