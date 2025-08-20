// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/BWSAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"
#include "AbilitySystemBlueprintLibrary.h"

UBWSAttributeSet::UBWSAttributeSet(const FObjectInitializer& ObjectInitializer)
{
    InitHealth(30.0f);
    InitMaxHealth(100.0f);
    InitMoney(500.0f);
}

void UBWSAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);

    if (Attribute == GetHealthAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
    }

    if (Attribute == GetMaxHealthAttribute())
    {
        NewValue = FMath::Max(NewValue, 0.0f);
    }

    if (Attribute == GetMoneyAttribute())
    {
        NewValue = FMath::Max(NewValue, 0.0f);
    }

}

void UBWSAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

    FEffectProperties Props;
    SetEffectProperties(Data, Props);
}

void UBWSAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const
{
    //Source - causer of effect, Target = target of effect (owner of this AS)

    Props.EffectContextHandle = Data.EffectSpec.GetContext();
    Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

    if (IsValid(Props.SourceASC) && Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid())
    {
        Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
        Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();

        if (!Props.SourceController && Props.SourceAvatarActor)
        {
            APawn* const Pawn = Cast<APawn>(Props.SourceAvatarActor);
            if (Pawn)
            {
                Props.SourceController = Pawn->GetController();
            }
        }

        if (Props.SourceController)
        {
            Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
        }
    }

    if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
    {
        Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
        Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
        Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);

        Props.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
    }
}

FEffectProperties::FEffectProperties()
    : SourceASC(nullptr)
    , SourceAvatarActor(nullptr)
    , SourceController(nullptr)
    , SourceCharacter(nullptr)
    , TargetASC(nullptr)
    , TargetAvatarActor(nullptr)
    , TargetController(nullptr)
    , TargetCharacter(nullptr)
{
}
