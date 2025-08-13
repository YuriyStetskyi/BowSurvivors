// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/BWSWidgetController.h"
#include "BWSOverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);

struct FOnAttributeChangeData;

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class BOWSURVIVORS_API UBWSOverlayWidgetController : public UBWSWidgetController
{
	GENERATED_BODY()
	
public:
    virtual void BroadcastInitialValues() override;

    virtual void BindCallbacksToDependencies() override;

    UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
    FOnHealthChangedSignature OnHealthChanged;

    UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
    FOnMaxHealthChangedSignature OnMaxHealthChanged;

protected:
    void HealthChanged(const FOnAttributeChangeData& Data);
    void MaxHealthChanged(const FOnAttributeChangeData& Data);


};
