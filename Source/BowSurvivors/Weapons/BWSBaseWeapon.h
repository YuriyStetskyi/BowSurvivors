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

    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
    UAttributeSet* GetAttributeSet() const { return AttributeSet; }

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

    virtual int32 GetCurrentLevel() override { return WeaponLevel; }

    /* Retuns Weapon Static mesh (might be skeletal in the future) */
    FORCEINLINE USkeletalMeshComponent* GetMesh() { return SkeletalMeshComponent; }

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

    UFUNCTION(BlueprintCallable)
    void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level);

    UPROPERTY(VisibleAnywhere)
    int32 WeaponLevel;

};
