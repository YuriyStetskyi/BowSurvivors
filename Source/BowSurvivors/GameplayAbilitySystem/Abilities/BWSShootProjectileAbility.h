// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySystem/Abilities/BWSGameplayAbility.h"
#include "Interaction/BWSCombatInterface.h"
#include "BWSShootProjectileAbility.generated.h"

class ABWSProjectile;
class UGameplayEffect;

/**
 *  Gameplay Ability that is performed when Player tries to shoot.
 */
UCLASS()
class BOWSURVIVORS_API UBWSShootProjectileAbility : public UBWSGameplayAbility
{
	GENERATED_BODY()
public:

protected:
    /* Main Gameplay Ability method. Runs when Ability is activated. */
    virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData);

    /* Class of projectile to spawn when shooting. */
    UPROPERTY(EditDefaultsOnly, Category = "Defaults")
    TSubclassOf<ABWSProjectile> SpawnedProjectileClass;

    /* Class of gameplay effect to be applied to target when projectile overlaps it. Usually a damage gameplay effect. */
    UPROPERTY(EditDefaultsOnly, Category = "Defaults")
    TSubclassOf<UGameplayEffect> DamageGameplayEffect;

    /* Contains all logic associated with gameplay changes when trying to shoot projectile. Called from blueprint.*/
    UFUNCTION(BlueprintCallable, Category = "Projectile")
    void ShootProjectile(const FVector& ProjectileTargetLocation);

    void Spawn(const FTransform& Transform);

    void SetTrajectory(IBWSCombatInterface* const WeaponActor, FTransform& SpawnTransform, const FVector& ProjectileTargetLocation);

    void SetSpawnLocation(IBWSCombatInterface* const WeaponActor, FTransform& SpawnTransform);

    void SetGameplayEffect(ABWSProjectile* const SpawnedProjectile);
};
