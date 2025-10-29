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
 * 
 */
class BOWSURVIVORS_API IBWSCombatInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface. 
public:

    virtual int32 GetCurrentLevel();

    virtual FVector GetWeaponSocketLocation(FName SocketName = "");
};
