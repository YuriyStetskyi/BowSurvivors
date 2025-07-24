// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Characters/BWSEnemyCharacter.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"

ABWSEnemyCharacter::ABWSEnemyCharacter()
{
    InitializeComponents();
}

void ABWSEnemyCharacter::BeginPlay()
{
    Super::BeginPlay();

    AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void ABWSEnemyCharacter::InitializeComponents()
{
    AbilitySystemComponent = CreateDefaultSubobject<UBWSAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AttributeSet = CreateDefaultSubobject<UBWSAttributeSet>(TEXT("AttributeSet"));
}
