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
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
    UBWSAttributeSet(const FObjectInitializer& ObjectInitializer);
	
protected:
    UPROPERTY(BlueprintReadOnly, Category = "Vitals")
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UBWSAttributeSet, Health);

    UPROPERTY(BlueprintReadOnly, Category = "Vitals")
    FGameplayAttributeData MaxHealth;
    ATTRIBUTE_ACCESSORS(UBWSAttributeSet, MaxHealth);

    UPROPERTY(BlueprintReadOnly, Category = "Vitals")
    FGameplayAttributeData Money;
    ATTRIBUTE_ACCESSORS(UBWSAttributeSet, Money);

private:

};
