// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/BWSAttributeSet.h"

UBWSAttributeSet::UBWSAttributeSet(const FObjectInitializer& ObjectInitializer)
{
    InitHealth(30.0f);
    InitMaxHealth(100.0f);
    InitMoney(500.0f);
}