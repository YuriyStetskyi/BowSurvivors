// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BWSBaseCharacter.generated.h"

/**
 *  Base class of all character type actors. All enemies, npcs and player should inherit this class.
 */
UCLASS()
class BOWSURVIVORS_API ABWSBaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    ABWSBaseCharacter();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    void InitializeComponents();

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    /* Create Components at BeginPlay() */
};
