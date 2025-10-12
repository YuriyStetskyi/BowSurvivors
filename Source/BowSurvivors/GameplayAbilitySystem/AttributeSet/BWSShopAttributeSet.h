// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"
#include "BWSShopAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSShopAttributeSet : public UBWSAttributeSet
{
	GENERATED_BODY()
	
public:
    UBWSShopAttributeSet(const FObjectInitializer& ObjectInitializer);

    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

    /* Amount of health character should lose when damaged by this weapons projectile */
    UPROPERTY(BlueprintReadOnly, Category = "Attributes | Shop ")
    FGameplayAttributeData RerollPrice;
    ATTRIBUTE_ACCESSORS(UBWSShopAttributeSet, RerollPrice);


};
