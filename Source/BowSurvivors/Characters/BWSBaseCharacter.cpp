// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Characters/BWSBaseCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"
#include "GameplayEffect.h"

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

    const FGameplayEffectContextHandle EffectContext = ASC->MakeEffectContext();
    const FGameplayEffectSpecHandle EffectSpecHandle = ASC->MakeOutgoingSpec(GameplayEffectClass, Level, EffectContext);
    ASC->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data.Get(), ASC);
}

void ABWSBaseCharacter::InitializeDefaultAttributes()
{
    ApplyEffectToSelf(MaxAttributesInitializerEffect, 1.0f);
    ApplyEffectToSelf(CurrentAttributesInitializerEffect, 1.0f);
}

// Called every frame
void ABWSBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void ABWSBaseCharacter::InitializeComponents()
{
}
