// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BWSGameModeBase.generated.h"

class ABWSPlayerCharacter;

/**
 *  Bow Survivors Game Mode class. Used for general setup.
 */
UCLASS()
class BOWSURVIVORS_API ABWSGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:

    ABWSGameModeBase(const FObjectInitializer& ObjectInitializer);

    /* Begin Play analog for GameMode class */
    virtual void StartPlay() override;
};
