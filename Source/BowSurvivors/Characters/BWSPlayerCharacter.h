// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BWSBaseCharacter.h"
#include "BWSPlayerCharacter.generated.h"

struct FInputActionValue;

class UBWSWeaponComponent;

/**
 *
 */
UCLASS()
class BOWSURVIVORS_API ABWSPlayerCharacter : public ABWSBaseCharacter
{
    GENERATED_BODY()

public:
    ABWSPlayerCharacter(const FObjectInitializer& ObjectInitializer);

    /* Move action */
    void Move(const FInputActionValue& InputActionValue);

    /* Shoot action */
    void Shoot(const FInputActionValue& InputActionValue);

protected:
    virtual void BeginPlay() override;

    void InitializeComponents();

    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UBWSWeaponComponent* WeaponComponent;

private:

};
