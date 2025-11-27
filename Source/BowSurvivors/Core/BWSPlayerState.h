// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Interaction/BWSCombatInterface.h"
#include "GameFramework/PlayerState.h"
#include "BWSPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 *  Default Player state class
 */
UCLASS()
class BOWSURVIVORS_API ABWSPlayerState : public APlayerState, public IAbilitySystemInterface, public IBWSCombatInterface
{
	GENERATED_BODY()
	
public:
    ABWSPlayerState();

    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
    UAttributeSet* GetAttributeSet() const { return AttributeSet; }

    /* Returns current level of character/player state associated with character. */
    virtual int32 GetCurrentLevel() override { return PlayerLevel; }

protected:
    /* Ability System Component - main part of Gameplay Ability System */
    UPROPERTY(EditDefaultsOnly, Category = "Components | GAS")
    UAbilitySystemComponent* AbilitySystemComponent;

    /* Attribute set - stores all values connected to Gameplay Ability System */
    UPROPERTY(EditDefaultsOnly, Category = "Components | GAS")
    UAttributeSet* AttributeSet;

private:
    /* Method that initializes all of the actors components */
    void InitializeComponents();

    /* Current Player Level. */
    UPROPERTY(VisibleAnywhere)
    int32 PlayerLevel;
};
