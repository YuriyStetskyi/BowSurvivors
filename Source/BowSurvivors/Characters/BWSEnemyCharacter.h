// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Interaction/BWSCombatInterface.h"
#include "Characters/BWSBaseCharacter.h"
#include "UI/WidgetController/BWSOverlayWidgetController.h"
#include "BWSEnemyCharacter.generated.h"

class UWidgetComponent;

/**
 *  Enemy Character class. Inherits ABWSBaseCharacter. Represents all enemies in the game.
 */
UCLASS()
class BOWSURVIVORS_API ABWSEnemyCharacter : public ABWSBaseCharacter, public IBWSCombatInterface
{
	GENERATED_BODY()
	
public:
    ABWSEnemyCharacter();

protected:
    
    /* Widget that displays HealthBar. */
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UWidgetComponent* HealthBarWidget;

    /* Delegate that is broadcasted when Health attribute is changed. */
    UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
    FOnAttributeChangedSignature OnHealthChanged;

    /* Delegate that is broadcasted when Max Health attribute is changed. */
    UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
    FOnAttributeChangedSignature OnMaxHealthChanged;

    virtual void BeginPlay() override;

    /* Initializes Ability Actor Info of character. */
    virtual void InitializeAbilityActorInfo() override;

    /* Returns current Character Level. */
    virtual int32 GetCurrentLevel() override { return EnemyLevel; }
private:
    /* Method that initializes all of the actors components */
    void InitializeComponents();

    /* Current Character Level. */
    UPROPERTY(VisibleAnywhere)
    int32 EnemyLevel;
};
