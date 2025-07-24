// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Characters/BWSBaseCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"

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

// Called every frame
void ABWSBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void ABWSBaseCharacter::InitializeComponents()
{
}
