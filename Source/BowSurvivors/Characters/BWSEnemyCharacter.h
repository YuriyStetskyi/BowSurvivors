// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Interaction/BWSCombatInterface.h"
#include "Characters/BWSBaseCharacter.h"
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
    
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UWidgetComponent* HealthBarWidget;

    virtual void BeginPlay() override;

    virtual void InitializeAbilityActorInfo() override;

    virtual int32 GetCurrentLevel() override { return EnemyLevel; }
private:
    /* Method that initializes all of the actors components */
    void InitializeComponents();

    UPROPERTY(VisibleAnywhere)
    int32 EnemyLevel;
};
