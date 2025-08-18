// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BWSEffectActor.generated.h"

class UGameplayEffect;

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

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

    UFUNCTION(BlueprintCallable)
    void ApplyEffectToTarget(AActor* const TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
