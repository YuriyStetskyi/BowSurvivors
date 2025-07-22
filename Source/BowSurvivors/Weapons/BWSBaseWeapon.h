// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BWSBaseWeapon.generated.h"

UCLASS()
class BOWSURVIVORS_API ABWSBaseWeapon : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ABWSBaseWeapon();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    virtual void Attack();

    FORCEINLINE UStaticMeshComponent* GetMesh() { return StaticMeshComponent; }

protected:

    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UStaticMeshComponent* StaticMeshComponent;
};
