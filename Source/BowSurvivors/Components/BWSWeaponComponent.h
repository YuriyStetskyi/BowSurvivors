// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BWSWeaponComponent.generated.h"

UENUM(BlueprintType)
enum class EWeaponSlot : uint8
{
    FisrtWeapon,
    SecondWeapon
};

class ABWSBaseWeapon;


/**
 *  Weapon component class that is attached to character and stores all weapon connected logic and data.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BOWSURVIVORS_API UBWSWeaponComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UBWSWeaponComponent();

    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // Called when the game starts
    virtual void BeginPlay() override;

    /* returns currently equipped weapon*/
    FORCEINLINE ABWSBaseWeapon* const GetCurrentWeapon() { return CurrentWeapon; }

    /* Performs attack depending on weapon */
    void Attack();

    /* Equips specified weapon */
    void EquipWeapon(ABWSBaseWeapon* const Weapon);

    /* Unequips specified weapon */
    void HolsterWeapon(ABWSBaseWeapon* const Weapon);

protected:
    /* Default BP that first weapon will be set to */
    UPROPERTY(EditDefaultsOnly, Category = "Weapons")
    TSubclassOf<ABWSBaseWeapon> DefaultFirstWeapon;

    /* Default BP that second weapon will be set to */
    UPROPERTY(EditDefaultsOnly, Category = "Weapons")
    TSubclassOf<ABWSBaseWeapon> DefaultSecondWeapon;

private:
    /* Equips weapon of specified slot, and unequips all others */
    void EquipWeaponSlot(EWeaponSlot WeaponToEquip);

    /* Spawns all the weapons at the beginning of the game */
    void SpawnWeapons();

    /* Currently equipped weapon. The weapon that is used to attack at this moment */
    UPROPERTY(VisibleAnywhere, Category = "Weapons")
    ABWSBaseWeapon* CurrentWeapon;

    /* First weapon in inventory */
    UPROPERTY(VisibleAnywhere, Category = "Weapons")
    ABWSBaseWeapon* FirstWeapon;

    /* Seocnd Weapon in inventory */
    UPROPERTY(VisibleAnywhere, Category = "Weapons")
    ABWSBaseWeapon* SecondWeapon;

    /*
        
        Name of socket to which weapon will be attached.
        Socket must exist on skeletal mesh of Character
    */
    UPROPERTY(EditDefaultsOnly, Category = "Weapons")
    FName WeaponSocketName;
};
