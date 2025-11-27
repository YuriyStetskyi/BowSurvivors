// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"
#include "BWSShopAttributeSet.generated.h"

/**
 *  Shopkeepers Attribute Set. Stores all attributes associated with shop.
 */
UCLASS()
class BOWSURVIVORS_API UBWSShopAttributeSet : public UBWSAttributeSet
{
	GENERATED_BODY()
	
public:
    UBWSShopAttributeSet(const FObjectInitializer& ObjectInitializer);

    /* Called before attribute is changed. */
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

    /* Called after gameplay effect is executed. */
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

    /* Current Shop Reroll Price */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Shop ")
    FGameplayAttributeData RerollPrice;
    ATTRIBUTE_ACCESSORS(UBWSShopAttributeSet, RerollPrice);


};
