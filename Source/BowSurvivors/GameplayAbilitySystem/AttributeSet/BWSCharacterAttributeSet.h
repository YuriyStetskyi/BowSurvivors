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

    /* Called before attribute is changed. */
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    
    /* Called after gameplay effect is executed. */
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

    /**
     *    Character Combat Attributes
     */

    /* Health property. Represents actors current Health amount */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Combat")
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UBWSCharacterAttributeSet, Health);

    /* Max Health property. Represents actors max Health amount */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Combat")
    FGameplayAttributeData MaxHealth;
    ATTRIBUTE_ACCESSORS(UBWSCharacterAttributeSet, MaxHealth);

    /* Characters Movement speed property. Represents characters speed while moving. */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Combat")
    FGameplayAttributeData MovementSpeed;
    ATTRIBUTE_ACCESSORS(UBWSCharacterAttributeSet, MovementSpeed)

    /* Property that represents how many dashes character is currently able to perform */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Combat")
    FGameplayAttributeData Dashes;
    ATTRIBUTE_ACCESSORS(UBWSCharacterAttributeSet, Dashes)

    /* Property that represents maximum amount of dashes charcater is able to perform */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Combat")
    FGameplayAttributeData MaxDashes;
    ATTRIBUTE_ACCESSORS(UBWSCharacterAttributeSet, MaxDashes)

    /**
     *    Character Economy Attributes
     */

    /* Money property. Represents actors current money amount */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Economy")
    FGameplayAttributeData Money;
    ATTRIBUTE_ACCESSORS(UBWSCharacterAttributeSet, Money);

    /* Experience points Property. Represents characters progress towards next level */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Economy")
    FGameplayAttributeData EXP;
    ATTRIBUTE_ACCESSORS(UBWSCharacterAttributeSet, EXP);

    /* Maximum Experience points Property. Describes number character has to achieve to level up (EXP) */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Economy")
    FGameplayAttributeData MaxEXP;
    ATTRIBUTE_ACCESSORS(UBWSCharacterAttributeSet, MaxEXP);

};
