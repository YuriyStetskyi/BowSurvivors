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

    FVector SocketLocation = WeaponActor->GetWeaponSocketLocation();
    FRotator ProjectileRotation = (ProjectileTargetLocation - WeaponActor->GetWeaponSocketLocation()).Rotation();
    ProjectileRotation.Pitch = 0.0f;

    FTransform SpawnTransform;
    SpawnTransform.SetLocation(SocketLocation);
    SpawnTransform.SetRotation(ProjectileRotation.Quaternion());

    UWorld* const World = GetWorld();
    if (!World) return;

    ABWSProjectile* const SpawnedProjectile = World->SpawnActorDeferred<ABWSProjectile>(SpawnedProjectileClass,
        SpawnTransform,
        GetOwningActorFromActorInfo(),
        Cast<APawn>(GetOwningActorFromActorInfo()),
        ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

    UAbilitySystemComponent* WeaponASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo());
    if (!WeaponASC) return;

    FGameplayEffectSpecHandle DamageEffectSpecHandle = WeaponASC->MakeOutgoingSpec(DamageGameplayEffect, 1, WeaponASC->MakeEffectContext());
    SpawnedProjectile->DamageEffectSpecHandle = DamageEffectSpecHandle;
    
    SpawnedProjectile->FinishSpawning(SpawnTransform);
}
