// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BWSBaseWeapon.generated.h"

/**
 *  Base Weapon class. Stores all weapon data and logic.
 */
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

    /*  
        Method that is called when weapon performs attack action. 
        Logic is overriden in more concrete weapon types - thus different for different wepaons
    */
    virtual void Attack();

    /* Retuns Weapon Static mesh (might be skeletal in the future) */
    FORCEINLINE UStaticMeshComponent* GetMesh() { return StaticMeshComponent; }

protected:

    /* Weapons Static Mesh */
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UStaticMeshComponent* StaticMeshComponent;
};
