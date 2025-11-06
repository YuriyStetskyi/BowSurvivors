// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BWSProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;
class UNiagaraSystem;

UCLASS()
class BOWSURVIVORS_API ABWSProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ABWSProjectile();

protected:
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Components")
    USphereComponent* SphereCollider;

    UPROPERTY(EditAnywhere, Category = "Components")
    UProjectileMovementComponent* ProjectileMovementComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Impact Data")
    UNiagaraSystem* ImpactEffect;

    UPROPERTY(EditDefaultsOnly, Category = "Impact Data")
    USoundBase* ImpactSound;

    UFUNCTION()
    void OnSphereColliderOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
