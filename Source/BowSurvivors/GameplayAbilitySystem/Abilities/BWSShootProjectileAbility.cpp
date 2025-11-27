// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/Abilities/BWSShootProjectileAbility.h"
#include "Interaction/BWSCombatInterface.h"
#include "Actors/BWSProjectile.h"
#include "GameplayEffect.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

void UBWSShootProjectileAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

    
}

void UBWSShootProjectileAbility::ShootProjectile(const FVector& ProjectileTargetLocation)
{
    IBWSCombatInterface* const WeaponActor = Cast<IBWSCombatInterface>(GetAvatarActorFromActorInfo());
    if (!WeaponActor) return;

    FTransform SpawnTransform;
    SetSpawnLocation(WeaponActor, SpawnTransform);
    SetTrajectory(WeaponActor, SpawnTransform, ProjectileTargetLocation);

    Spawn(SpawnTransform);
}

void UBWSShootProjectileAbility::Spawn(const FTransform& Transform)
{
    UWorld* const World = GetWorld();
    if (!World) return;

    ABWSProjectile* const SpawnedProjectile = World->SpawnActorDeferred<ABWSProjectile>(SpawnedProjectileClass,
        Transform,
        GetOwningActorFromActorInfo(),
        Cast<APawn>(GetOwningActorFromActorInfo()),
        ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

    SetGameplayEffect(SpawnedProjectile);

    SpawnedProjectile->FinishSpawning(Transform);
}

void UBWSShootProjectileAbility::SetTrajectory(IBWSCombatInterface* const WeaponActor, FTransform& SpawnTransform, const FVector& ProjectileTargetLocation)
{
    FRotator ProjectileRotation = (ProjectileTargetLocation - WeaponActor->GetWeaponSocketLocation()).Rotation();
    ProjectileRotation.Pitch = 0.0f;
    SpawnTransform.SetRotation(ProjectileRotation.Quaternion());
}

void UBWSShootProjectileAbility::SetSpawnLocation(IBWSCombatInterface* const WeaponActor, FTransform& SpawnTransform)
{
    FVector SocketLocation = WeaponActor->GetWeaponSocketLocation();
    SpawnTransform.SetLocation(SocketLocation);
}

void UBWSShootProjectileAbility::SetGameplayEffect(ABWSProjectile* const SpawnedProjectile)
{
    UAbilitySystemComponent* WeaponASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo());
    if (!WeaponASC) return;

    FGameplayEffectSpecHandle DamageEffectSpecHandle = WeaponASC->MakeOutgoingSpec(DamageGameplayEffect, 1, WeaponASC->MakeEffectContext());
    SpawnedProjectile->DamageEffectSpecHandle = DamageEffectSpecHandle;
}
