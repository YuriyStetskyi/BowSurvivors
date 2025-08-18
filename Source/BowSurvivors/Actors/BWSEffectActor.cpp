// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Actors/BWSEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"

// Sets default values
ABWSEffectActor::ABWSEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

// Called when the game starts or when spawned
void ABWSEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABWSEffectActor::ApplyEffectToTarget(AActor* const TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
    UAbilitySystemComponent* const TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
    if (!TargetASC) return;

    check(GameplayEffectClass);

    FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
    EffectContextHandle.AddSourceObject(this);

    FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1, EffectContextHandle);

    TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());         
}

// Called every frame
void ABWSEffectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

