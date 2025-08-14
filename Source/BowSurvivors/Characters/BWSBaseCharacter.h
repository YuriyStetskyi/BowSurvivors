// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "BWSBaseCharacter.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 *  Base class of all character type actors. All enemies, npcs and player should inherit this class.
 */
UCLASS()
class BOWSURVIVORS_API ABWSBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    ABWSBaseCharacter();

    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
    UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    /* Method that initializes all of the actors components */
    void InitializeComponents();

    /* Ability System Component - main part of Gameplay Ability System */
    UPROPERTY(EditDefaultsOnly, Category = "Components | GAS")
    UAbilitySystemComponent* AbilitySystemComponent;

    /* Attribute set - stores all values (attributes) connected to Gameplay Ability System */
    UPROPERTY(EditDefaultsOnly, Category = "Components | GAS")
    UAttributeSet* AttributeSet;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

};
