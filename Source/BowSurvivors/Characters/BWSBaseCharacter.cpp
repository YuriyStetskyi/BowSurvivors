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

void ABWSBaseCharacter::InitializeDefaultAttributes() const
{
    UAbilitySystemComponent* const ASC = GetAbilitySystemComponent();
    check(IsValid(ASC));
    
    checkf(DefaultAttributes, TEXT("Please set DefaultAttributes in Character that triggered a crash "));

    const FGameplayEffectContextHandle EffectContext = ASC->MakeEffectContext();
    const FGameplayEffectSpecHandle EffectSpecHandle = ASC->MakeOutgoingSpec(DefaultAttributes, 1.0f, EffectContext);
    ASC->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data.Get(), ASC);
}

// Called every frame
void ABWSBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void ABWSBaseCharacter::InitializeComponents()
{
}
