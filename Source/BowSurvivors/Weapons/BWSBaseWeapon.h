// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Interaction/BWSCombatInterface.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Actor.h"
#include "BWSBaseWeapon.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;

/**
 *  Base Weapon class. Stores all weapon data and logic.
 */
UCLASS()
class BOWSURVIVORS_API ABWSBaseWeapon : public AActor, public IAbilitySystemInterface, public IBWSCombatInterface
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ABWSBaseWeapon();

    /* Returns Weapons Ability System Component */
    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

    /* Returns Weapons Attribute Set */
    UAttributeSet* GetAttributeSet() const { return AttributeSet; }

    /* 
        Gets location in world of where the weapon is supposed to be located.
        if argument passed - will find specified socket with name that is passed 
    */
    virtual FVector GetWeaponSocketLocation(FName SocketName = "") override;

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    /*  
        Method that is called when weapon performs attack action. 
        Logic is overriden in more concrete weapon types - thus different for different wepaons
    */
    virtual void Attack();

    /* Get Current weapon level */
    virtual int32 GetCurrentLevel() override { return WeaponLevel; }

    /* Retuns Weapon Static mesh (might be skeletal in the future) */
    UFUNCTION(BlueprintCallable)
    USkeletalMeshComponent* GetMesh() { return SkeletalMeshComponent; }

protected:
    /* Ability System Component - main part of Gameplay Ability System */
    UPROPERTY(EditDefaultsOnly, Category = "Components | GAS")
    UAbilitySystemComponent* AbilitySystemComponent;

    /* Attribute set - stores all values (attributes) connected to Gameplay Ability System */
    UPROPERTY(EditDefaultsOnly, Category = "Components | GAS")
    UAttributeSet* AttributeSet;

    /* Weapons Static Mesh */
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    USkeletalMeshComponent* SkeletalMeshComponent;

    /* Effect that initializes core weapon stats: Damage, FireRate, Range, NumOfArrows, Speed, Size. */
    UPROPERTY(EditDefaultsOnly, Category = "Attributes")
    TSubclassOf<UGameplayEffect> DefaultCoreWeaponAttributesInitializerEffect;

    /* Effect that initializes Derived weapon stats: DPS, Utility Score. */
    UPROPERTY(EditDefaultsOnly, Category = "Attributes")
    TSubclassOf<UGameplayEffect> DefaultDerivedWeaponAttributesInitializerEffect;

    /* Effect that initializes general weapon score. */
    UPROPERTY(EditDefaultsOnly, Category = "Attributes")
    TSubclassOf<UGameplayEffect> DefaultWeaponScoreAttributesInitializerEffect;

private:
    /* Initializes components */
    void InitializeComponents();

    /* Initializes Ability Actor Info */
    void InitializeAbilityActorInfo();

    /* Initializes Default Attributes */
    void InitializeDefaultAttributes();

    /* Generates attributes for weapon. In the future will be used when rerolling stats. */
    void GenerateAttributes();

    /* Applied passed as argument effect to self*/
    UFUNCTION(BlueprintCallable)
    void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level);

    /* Weapons Current level. */
    UPROPERTY(VisibleAnywhere)
    int32 WeaponLevel;

};
