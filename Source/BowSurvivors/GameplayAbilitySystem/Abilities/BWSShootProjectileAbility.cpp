// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/Abilities/BWSShootProjectileAbility.h"
#include "Interaction/BWSCombatInterface.h"
#include "Actors/BWSProjectile.h"

void UBWSShootProjectileAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

    
}

void UBWSShootProjectileAbility::ShootProjectile()
{
    IBWSCombatInterface* const ActorCombat = Cast<IBWSCombatInterface>(GetAvatarActorFromActorInfo());
    if (!ActorCombat) return;

    FTransform SpawnTransform;
    SpawnTransform.SetLocation(ActorCombat->GetWeaponSocketLocation());

    // Set Rotation Later

    UWorld* const World = GetWorld();
    if (!World) return;

    ABWSProjectile* const SpawnedProjectile = World->SpawnActorDeferred<ABWSProjectile>(SpawnedProjectileClass,
        SpawnTransform,
        GetOwningActorFromActorInfo(),
        Cast<APawn>(GetOwningActorFromActorInfo()),
        ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

    // GiveProjectile gameplay effect for dealing damage

    SpawnedProjectile->FinishSpawning(SpawnTransform);
}
