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

/**
 *  If actor has Ability System Component - Attribute Set stores all the attributes to be interacted with.
 */
UCLASS()
class BOWSURVIVORS_API UBWSAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
    UBWSAttributeSet(const FObjectInitializer& ObjectInitializer);
	
    /* Health property. Represents actors current Health amount */
    UPROPERTY(BlueprintReadOnly, Category = "Vitals")
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UBWSAttributeSet, Health);

    /* Max Health property. Represents actors max Health amount */
    UPROPERTY(BlueprintReadOnly, Category = "Vitals")
    FGameplayAttributeData MaxHealth;
    ATTRIBUTE_ACCESSORS(UBWSAttributeSet, MaxHealth);

    /* Money property. Represents actors current money amount */
    UPROPERTY(BlueprintReadOnly, Category = "Vitals")
    FGameplayAttributeData Money;
    ATTRIBUTE_ACCESSORS(UBWSAttributeSet, Money);

private:

};
