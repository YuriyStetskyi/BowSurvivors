// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BWSBaseCharacter.h"
#include "BWSPlayerCharacter.generated.h"

struct FInputActionValue;

class UCameraComponent;
class USpringArmComponent;
class UBWSWeaponComponent;

/**
 *  Player Character class. Stores player specific data and logic.
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

    /* Getters */
    FORCEINLINE USpringArmComponent* const GetSpringArmComponen() { return SpringArmComponent; }
    FORCEINLINE UCameraComponent* const GetCameraComponent() { return CameraComponent; }

protected:
    virtual void BeginPlay() override;

    void InitializeComponents();

    /* Main Character Spring Arm that has camera attached to it */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    /* Main Character third person Camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UCameraComponent* CameraComponent;

    /* Component that stores all weapons and their data */
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UBWSWeaponComponent* WeaponComponent;


private:

};
