// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Weapons/BWSBaseWeapon.h"

// Sets default values
ABWSBaseWeapon::ABWSBaseWeapon()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    StaticMeshComponent->SetupAttachment(GetRootComponent());
    StaticMeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    StaticMeshComponent->SetEnableGravity(false);
}

// Called when the game starts or when spawned
void ABWSBaseWeapon::BeginPlay()
{
    Super::BeginPlay();

}

void ABWSBaseWeapon::Attack()
{

}

// Called every frame
void ABWSBaseWeapon::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

