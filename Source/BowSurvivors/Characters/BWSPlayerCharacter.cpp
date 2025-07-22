// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Characters/BWSPlayerCharacter.h"
#include "InputActionValue.h"
#include "Components/BWSWeaponComponent.h"

ABWSPlayerCharacter::ABWSPlayerCharacter(const FObjectInitializer& ObjectInitializer)
    : WeaponComponent(nullptr)
{
    InitializeComponents();
}

void ABWSPlayerCharacter::Move(const FInputActionValue& InputActionValue)
{
    const FVector2D MovementVector = InputActionValue.Get<FVector2D>();

    AddMovementInput(FVector::ForwardVector, MovementVector.Y);
    AddMovementInput(FVector::RightVector, MovementVector.X);
}

void ABWSPlayerCharacter::Shoot(const FInputActionValue& InputActionValue)
{
    WeaponComponent->Attack();
}

void ABWSPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ABWSPlayerCharacter::InitializeComponents()
{
    WeaponComponent = CreateDefaultSubobject<UBWSWeaponComponent>(TEXT("WeaponComponent"));
}
