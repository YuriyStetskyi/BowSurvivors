// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BWSCombatInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBWSCombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *  Interface that stores all functions connected to games combat.
 */
class BOWSURVIVORS_API IBWSCombatInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface. 
public:

    /* Returns current level of object implementing this interface. */
    virtual int32 GetCurrentLevel();

    /* Returns Weapon socket location of weapon owned by object implementing this interface. */
    virtual FVector GetWeaponSocketLocation(FName SocketName = "");
};
