// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BWSBaseCharacter.h"
#include "BWSEnemyCharacter.generated.h"

/**
 *  Enemy Character class. Inherits ABWSBaseCharacter. Represents all enemies in the game.
 */
UCLASS()
class BOWSURVIVORS_API ABWSEnemyCharacter : public ABWSBaseCharacter
{
	GENERATED_BODY()
	
public:
    ABWSEnemyCharacter();

protected:
    virtual void BeginPlay() override;

private:
    /* Method that initializes all of the actors components */
    void InitializeComponents();

};
