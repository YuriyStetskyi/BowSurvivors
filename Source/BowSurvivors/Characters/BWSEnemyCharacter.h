// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BWSBaseCharacter.h"
#include "BWSEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API ABWSEnemyCharacter : public ABWSBaseCharacter
{
	GENERATED_BODY()
	
public:
    ABWSEnemyCharacter();

protected:

private:
    /* Method that initializes all of the actors components */
    void InitializeComponents();

};
