// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BWSAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT(BlueprintType)
struct FEffectProperties
{
    GENERATED_BODY()

    FEffectProperties();

    FGameplayEffectContextHandle EffectContextHandle;

    UPROPERTY()
    UAbilitySystemComponent* SourceASC;

    UPROPERTY()
    AActor* SourceAvatarActor;

    UPROPERTY()
    AController* SourceController;

    UPROPERTY()
    ACharacter* SourceCharacter;

    UPROPERTY()
    UAbilitySystemComponent* TargetASC;

    UPROPERTY()
    AActor* TargetAvatarActor;

    UPROPERTY()
    AController* TargetController;

    UPROPERTY()
    ACharacter* TargetCharacter;

};


/**
 *  If actor has Ability System Component - Attribute Set stores all the attributes to be interacted with.
 */
UCLASS()
class BOWSURVIVORS_API UBWSAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
    UBWSAttributeSet();
    UBWSAttributeSet(const FObjectInitializer& ObjectInitializer);

    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

private:
    void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;

};
