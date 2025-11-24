// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "BWSEffectActor.generated.h"

class UGameplayEffect;
class UAbilitySystemComponent;

/* Application policy of gameplay effect. Determines when and if effect is applied. */
UENUM(BlueprintType)
enum class EEffectApplicationPolicy : uint8
{     
    ApplyOnOverlap,
    ApplyOnEndOverlap,
    DoNotApply
};

/* Removal policy of gameplay effect. Determines when is effect removed. */
UENUM(BlueprintType)
enum class EEffectRemovalPolicy : uint8
{
    RemoveOnEndOverlap,
    DoNotRemove
};

/** 
 *  Gameplay Ability System effect actor that can apply effect with different application/removal policies.
 */
UCLASS()
class BOWSURVIVORS_API ABWSEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABWSEffectActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    /* Applies effect to target. */
    UFUNCTION(BlueprintCallable)
    void ApplyEffectToTarget(AActor* const TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

    /* Called when Gameplay effect actor is overlapped. */
    UFUNCTION(BlueprintCallable)
    void OnOverlap(AActor* const TargetActor);

    /* Called when Effect Actor stops overlaping some other actor.*/
    UFUNCTION(BlueprintCallable)
    void OnEndOverlap(AActor* const TargetActor);

    /* If true - effect actor is destroyed on removal. (NOT IMPLEMENTED YET) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    bool bDestroyOnRemoval;

    /* Instant gameplay effect to be created and applied */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

    /* Application policy of INSTANT gameplay effect. Determines when and if effect is applied. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    EEffectApplicationPolicy InstantEffectApplicationPolicy;

    /* Duration gameplay effect to be created and applied */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;

    /* Application policy of DURATION gameplay effect. Determines when and if effect is applied. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    EEffectApplicationPolicy DurationEffectApplicationPolicy;

    /* Infinite gameplay effect to be created and applied */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;

    /* Application policy of INFINITE gameplay effect. Determines when and if effect is applied. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    EEffectApplicationPolicy InfiniteEffectApplicationPolicy;

    /* Removal policy of INFINITE gameplay effect. Determines when and if effect is Removed. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    EEffectRemovalPolicy InfiniteEffectRemovalPolicy;

    /* GameplayEffectHandles of effects currently active of this Effect Actor. */
    TMap <FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandles;

    /* Level of this Gameplay Effect Actor. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    float ActorLevel;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
