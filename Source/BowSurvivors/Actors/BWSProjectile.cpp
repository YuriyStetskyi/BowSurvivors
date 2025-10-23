// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Actors/BWSProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

ABWSProjectile::ABWSProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

    SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
    SetRootComponent(SphereCollider);
    SphereCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    SphereCollider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    SphereCollider->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);
    SphereCollider->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Overlap);
    SphereCollider->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

    ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
    ProjectileMovementComponent->InitialSpeed = 550.0f;
    ProjectileMovementComponent->MaxSpeed = 550.0f;
    ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
}

void ABWSProjectile::BeginPlay()
{
	Super::BeginPlay();

    SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ABWSProjectile::OnSphereColliderOverlap);
}

void ABWSProjectile::OnSphereColliderOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    GEngine->AddOnScreenDebugMessage(1, 5, FColor::Orange, "--- projectile overlapped something ---");
}
