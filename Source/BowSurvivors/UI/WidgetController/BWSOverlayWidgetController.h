// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/BWSWidgetController.h"
#include "BWSOverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoneyChangedSignature, float, NewMoney);

struct FOnAttributeChangeData;

/**
 *  Overlay Widget Controller class. Controls OverlayWidget.
 */
UCLASS(BlueprintType, Blueprintable)
class BOWSURVIVORS_API UBWSOverlayWidgetController : public UBWSWidgetController
{
	GENERATED_BODY()
	
public:
    /* Runs delegates that hopefully update Initial data displayed in Overlay Widget. */
    virtual void BroadcastInitialValues() override;

    /* Bind appropriate methods to delegates that are broadcasted on attribute change. */
    virtual void BindCallbacksToDependencies() override;

    /* Broadcasted when health is changed. */
    UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
    FOnHealthChangedSignature OnHealthChanged;

    /* Broadcasted when Maximum Health is changed */
    UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
    FOnMaxHealthChangedSignature OnMaxHealthChanged;

    /* Broadcasted when current Money amount is changed */
    UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
    FOnMoneyChangedSignature OnMoneyChanged;

protected:
    /* Bound to Health attribute changed delegate in GAS. Broadcasts OnHealthChanged */
    void HealthChanged(const FOnAttributeChangeData& Data);

    /* Bound to MaxHealth attribute changed delegate in GAS. Broadcasts OnMaxHealthChanged */
    void MaxHealthChanged(const FOnAttributeChangeData& Data);

    /* Bound to Money attribute changed delegate in GAS. Broadcasts OnMoneyChanged */
    void MoneyChanged(const FOnAttributeChangeData& Data);

};
