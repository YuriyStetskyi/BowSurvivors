// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Actors/BWSEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"

// Sets default values
ABWSEffectActor::ABWSEffectActor()
    : bDestroyOnRemoval(false)
    , InstantEffectApplicationPolicy(EEffectApplicationPolicy::DoNotApply)
    , DurationEffectApplicationPolicy(EEffectApplicationPolicy::DoNotApply)
    , InfiniteEffectApplicationPolicy(EEffectApplicationPolicy::DoNotApply)
    , InfiniteEffectRemovalPolicy(EEffectRemovalPolicy::DoNotRemove)
    , ActorLevel(1.0f)
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

    FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, ActorLevel, EffectContextHandle);

    FActiveGameplayEffectHandle ActiveEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());  

    const bool bIsInfinite = EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite;
    if (bIsInfinite && InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
    {
        ActiveEffectHandles.Add(ActiveEffectHandle, TargetASC);
    }

}

void ABWSEffectActor::OnOverlap(AActor* const TargetActor)
{
    if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
    {
        ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
    }

    if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
    {
        ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
    }
    
    if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
    {
        ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
    }

}

void ABWSEffectActor::OnEndOverlap(AActor* const TargetActor)
{
    if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
    {
        ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
    }

    if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
    {
        ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
    }

    if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
    {
        ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
    }

    if (InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
    {
        UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
        if (!IsValid(TargetASC)) return;

        TArray<FActiveGameplayEffectHandle> HandlesToRemove;

        for (TPair<FActiveGameplayEffectHandle,UAbilitySystemComponent*> HandlePair : ActiveEffectHandles)
        {
            if (TargetASC == HandlePair.Value)
            {
                int32 NumberOfStacksToRemove = 1;
                TargetASC->RemoveActiveGameplayEffect(HandlePair.Key, NumberOfStacksToRemove);
                HandlesToRemove.Add(HandlePair.Key);
            }
        }

        for (FActiveGameplayEffectHandle& Handle : HandlesToRemove)
        {
            ActiveEffectHandles.FindAndRemoveChecked(Handle);
        }
    }
}

// Called every frame
void ABWSEffectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

