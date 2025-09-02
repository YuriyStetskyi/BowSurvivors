// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"
#include "BWSCharacterAttributeSet.generated.h"

/**
 * Attribute Set for Characters Attributes
 */
UCLASS()
class BOWSURVIVORS_API UBWSCharacterAttributeSet : public UBWSAttributeSet
{
	GENERATED_BODY()
	
public:
    UBWSCharacterAttributeSet(const FObjectInitializer& ObjectInitializer);

    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

    /* Health property. Represents actors current Health amount */
    UPROPERTY(BlueprintReadOnly, Category = "Vitals")
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UBWSCharacterAttributeSet, Health);

    /* Max Health property. Represents actors max Health amount */
    UPROPERTY(BlueprintReadOnly, Category = "Vitals")
    FGameplayAttributeData MaxHealth;
    ATTRIBUTE_ACCESSORS(UBWSCharacterAttributeSet, MaxHealth);

    /* Money property. Represents actors current money amount */
    UPROPERTY(BlueprintReadOnly, Category = "Vitals")
    FGameplayAttributeData Money;
    ATTRIBUTE_ACCESSORS(UBWSCharacterAttributeSet, Money);

};
