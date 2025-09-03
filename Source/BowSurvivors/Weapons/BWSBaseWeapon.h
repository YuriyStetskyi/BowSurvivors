// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
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
class BOWSURVIVORS_API ABWSBaseWeapon : public AActor, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ABWSBaseWeapon();

    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    /*  
        Method that is called when weapon performs attack action. 
        Logic is overriden in more concrete weapon types - thus different for different wepaons
    */
    virtual void Attack();

    /* Retuns Weapon Static mesh (might be skeletal in the future) */
    FORCEINLINE UStaticMeshComponent* GetMesh() { return StaticMeshComponent; }

protected:
    /* Ability System Component - main part of Gameplay Ability System */
    UPROPERTY(EditDefaultsOnly, Category = "Components | GAS")
    UAbilitySystemComponent* AbilitySystemComponent;

    /* Attribute set - stores all values (attributes) connected to Gameplay Ability System */
    UPROPERTY(EditDefaultsOnly, Category = "Components | GAS")
    UAttributeSet* AttributeSet;

    /* Weapons Static Mesh */
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UStaticMeshComponent* StaticMeshComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Attributes")
    TSubclassOf<UGameplayEffect> DefaultCoreWeaponAttributesInitializerEffect;

    UPROPERTY(EditDefaultsOnly, Category = "Attributes")
    TSubclassOf<UGameplayEffect> DefaultDerivedWeaponAttributesInitializerEffect;

    UPROPERTY(EditDefaultsOnly, Category = "Attributes")
    TSubclassOf<UGameplayEffect> DefaultWeaponScoreAttributesInitializerEffect;

private:
    void InitializeComponents();

    void InitializeAbilityActorInfo();

    void InitializeDefaultAttributes();

    void GenerateAttributes();

    void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level);

};
