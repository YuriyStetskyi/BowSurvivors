// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BWSBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class BOWSURVIVORS_API ABWSBaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    ABWSBaseCharacter();

    /* Getters */
    FORCEINLINE USpringArmComponent* const GetSpringArmComponen() { return SpringArmComponent; }
    FORCEINLINE UCameraComponent* const GetCameraComponent() { return CameraComponent; }

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    /* Main Character Spring Arm that has camera attached to it */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    /* Main Character third person Camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UCameraComponent* CameraComponent;

    void InitializeComponents();

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    /* Create Components at BeginPlay() */
};
