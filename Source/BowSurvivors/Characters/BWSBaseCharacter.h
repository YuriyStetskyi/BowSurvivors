// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "BWSBaseCharacter.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;
class UGameplayAbility;

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

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    /* Gets Ability System Component. */
    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

    /* Gets Attribute Set. */
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

    /* Should be overriden in child class. Initializes Ability Actor Info. */
    virtual void InitializeAbilityActorInfo();

    /* Effect that is self applied at BeginPlay() and initializes Max Attributes*/
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
    TSubclassOf<UGameplayEffect> MaxAttributesInitializerEffect;

    /* Effect that is self applied at BeginPlay() and initializes Current Attributes*/
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
    TSubclassOf<UGameplayEffect> CurrentAttributesInitializerEffect;

    /* Applies Gameplay Effect to self. (ASC is obtained automatically depending on child class GetASC override) */
    void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level);

    /* Initializes Default Attributes. */
    void InitializeDefaultAttributes();

    /* Adds startup gameplay abilities. */
    void AddCharacterAbilities();

private:

    /* Abilities to be added at start of play. */
    UPROPERTY(EditAnywhere, Category = "GAS | Abilities")
    TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

};
