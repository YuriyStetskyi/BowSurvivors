// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BWSBaseCharacter.h"
#include "Interaction/BWSCombatInterface.h"
#include "BWSPlayerCharacter.generated.h"

struct FInputActionValue;

class UCameraComponent;
class USpringArmComponent;
class UBWSWeaponComponent;
class ABWSPlayerState;

/**
 *  Player Character class. Stores player specific data and logic.
 */
UCLASS()
class BOWSURVIVORS_API ABWSPlayerCharacter : public ABWSBaseCharacter, public IBWSCombatInterface
{
    GENERATED_BODY()

public:
    ABWSPlayerCharacter(const FObjectInitializer& ObjectInitializer);

    /* Returns location of socket that weapon is supposed to be attached to. */
    virtual FVector GetWeaponSocketLocation(FName SocketName = "") override;

    /* Move action */
    void Move(const FInputActionValue& InputActionValue);

    /* Getters */
    FORCEINLINE USpringArmComponent* const GetSpringArmComponent() { return SpringArmComponent; }
    FORCEINLINE UCameraComponent* const GetCameraComponent() { return CameraComponent; }
    FORCEINLINE UBWSWeaponComponent* const GetWeaponComponent() { return WeaponComponent; }

    /* Returns current character level. */
    int32 GetCurrentLevel();

    /* Name of socket at which location projectile should spawn and start moving from. */
    UPROPERTY(EditDefaultsOnly, Category = "Sockets")
    FName ProjectileStartSocketName;

protected:
    /* Called at game start. */
    virtual void BeginPlay() override;

    /* Called when Character is possessed by a Controller */
    virtual void PossessedBy(AController* NewController) override;

    /* Main Character Spring Arm that has camera attached to it */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    /* Main Character third person Camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UCameraComponent* CameraComponent;

    /* Component that stores all weapons and their data */
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UBWSWeaponComponent* WeaponComponent;

    /* Initialize AbilitySystem Info and Component/AttributeSet pointers from PlayerState */
    virtual void InitializeAbilityActorInfo() override; 

private:
    /* Initializes main components of character (on compile) */
    void InitializeComponents();

    /* Initializes Overlay from HUD class. */
    void InitializeOverlay(ABWSPlayerState* const BWSPlayerState);
};
