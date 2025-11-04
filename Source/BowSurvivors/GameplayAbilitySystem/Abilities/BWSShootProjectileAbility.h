// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySystem/Abilities/BWSGameplayAbility.h"
#include "BWSShootProjectileAbility.generated.h"

class ABWSProjectile;

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSShootProjectileAbility : public UBWSGameplayAbility
{
	GENERATED_BODY()
public:

protected:
    virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData);

    UPROPERTY(EditDefaultsOnly, Category = "Defaults")
    TSubclassOf<ABWSProjectile> SpawnedProjectileClass;

    UFUNCTION(BlueprintCallable, Category = "Projectile")
    void ShootProjectile();
};
