// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "UI/WidgetController/BWSOverlayWidgetController.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"

void UBWSOverlayWidgetController::BroadcastInitialValues()
{
    UBWSAttributeSet* const BWSAttributeSet = Cast<UBWSAttributeSet>(AttributeSet);
    if (!BWSAttributeSet) return;

    OnHealthChanged.Broadcast(BWSAttributeSet->GetHealth());
    OnMaxHealthChanged.Broadcast(BWSAttributeSet->GetMaxHealth());
    OnMoneyChanged.Broadcast(BWSAttributeSet->GetMoney());
}

void UBWSOverlayWidgetController::BindCallbacksToDependencies()
{
    UBWSAttributeSet* const BWSAttributeSet = Cast<UBWSAttributeSet>(AttributeSet);
    if (!BWSAttributeSet) return;
   
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        BWSAttributeSet->GetHealthAttribute()).AddUObject(this, &UBWSOverlayWidgetController::HealthChanged);

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        BWSAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UBWSOverlayWidgetController::MaxHealthChanged);

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        BWSAttributeSet->GetMoneyAttribute()).AddUObject(this, &UBWSOverlayWidgetController::MoneyChanged);
}

void UBWSOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data)
{
    OnHealthChanged.Broadcast(Data.NewValue);
}

void UBWSOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data)
{
    OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UBWSOverlayWidgetController::MoneyChanged(const FOnAttributeChangeData& Data)
{
    OnMoneyChanged.Broadcast(Data.NewValue);
}
