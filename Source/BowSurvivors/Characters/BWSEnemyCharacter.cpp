// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Characters/BWSEnemyCharacter.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AttributeSet/BWSCharacterAttributeSet.h"

ABWSEnemyCharacter::ABWSEnemyCharacter()
    : EnemyLevel(1)
{
    InitializeComponents();
}

void ABWSEnemyCharacter::BeginPlay()
{
    Super::BeginPlay();

    InitializeAbilityActorInfo();
}

void ABWSEnemyCharacter::InitializeAbilityActorInfo()
{
    AbilitySystemComponent->InitAbilityActorInfo(this, this);

    UBWSAbilitySystemComponent* const ASC = Cast<UBWSAbilitySystemComponent>(AbilitySystemComponent);
    if (!ASC) return;

    InitializeDefaultAttributes();

    ASC->AbilityActorInfoSet();
}

void ABWSEnemyCharacter::InitializeComponents()
{
    AbilitySystemComponent = CreateDefaultSubobject<UBWSAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AttributeSet = CreateDefaultSubobject<UBWSCharacterAttributeSet>(TEXT("AttributeSet"));
}
