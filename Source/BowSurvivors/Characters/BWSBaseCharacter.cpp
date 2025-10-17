// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Characters/BWSBaseCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"
#include "GameplayEffect.h"
#include "Abilities/GameplayAbility.h"

// Sets default values
ABWSBaseCharacter::ABWSBaseCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    InitializeComponents();
}

UAbilitySystemComponent* ABWSBaseCharacter::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void ABWSBaseCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ABWSBaseCharacter::InitializeAbilityActorInfo()
{

}

void ABWSBaseCharacter::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level)
{
    UAbilitySystemComponent* const ASC = GetAbilitySystemComponent();
    check(IsValid(ASC));

    check(GameplayEffectClass);

    FGameplayEffectContextHandle EffectContext = ASC->MakeEffectContext();
    EffectContext.AddSourceObject(this);
    const FGameplayEffectSpecHandle EffectSpecHandle = ASC->MakeOutgoingSpec(GameplayEffectClass, Level, EffectContext);
    ASC->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data.Get(), ASC);
}

void ABWSBaseCharacter::InitializeDefaultAttributes()
{
    ApplyEffectToSelf(MaxAttributesInitializerEffect, 1.0f);
    ApplyEffectToSelf(CurrentAttributesInitializerEffect, 1.0f);
}

void ABWSBaseCharacter::AddCharacterAbilities()
{
    UBWSAbilitySystemComponent* const ASC = Cast<UBWSAbilitySystemComponent>(AbilitySystemComponent);
    if (!ASC) return;

    ASC->AddCharacterAbilities(StartupAbilities);
}

// Called every frame
void ABWSBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void ABWSBaseCharacter::InitializeComponents()
{
}
