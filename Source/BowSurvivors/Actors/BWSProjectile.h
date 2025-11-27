// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "BWSProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;
class UNiagaraSystem;

/**
 *  Default projectile class.
 */
UCLASS()
class BOWSURVIVORS_API ABWSProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ABWSProjectile();

    /* Gameplay Spec Handle for Damage Effect applied by projectile. */
    UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
    FGameplayEffectSpecHandle DamageEffectSpecHandle;

protected:
	virtual void BeginPlay() override;

    /* Collider that determines projectiles collision radius. */
    UPROPERTY(EditAnywhere, Category = "Components")
    USphereComponent* SphereCollider;

    /* Movement component for projectile. Determines its movement. */
    UPROPERTY(EditAnywhere, Category = "Components")
    UProjectileMovementComponent* ProjectileMovementComponent;

    /* Niagara effect played on Projectile impact. */
    UPROPERTY(EditDefaultsOnly, Category = "Impact Data")
    UNiagaraSystem* ImpactEffect;

    /* Sound effect played on Projectile impact. */
    UPROPERTY(EditDefaultsOnly, Category = "Impact Data")
    USoundBase* ImpactSound;

    /* Method called when Projectiles Sphere Collider is overlapped with another actor. */
    UFUNCTION()
    void OnSphereColliderOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    /* Performs all visual changes when projectile is overlapped with another actor. */
    void ManageOnOverlapVisuals();
    
    /* Performs all audio changes when projectile is overlapped with another actor. */
    void ManageOnOverlapAudio();

    /* Performs all gameplay changes when projectile is overlapped with another actor. */
    void ManageOnOverlapGameplay(AActor* OtherActor);
};
