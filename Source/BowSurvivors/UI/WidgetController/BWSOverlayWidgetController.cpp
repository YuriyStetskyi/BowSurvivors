// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "UI/WidgetController/BWSOverlayWidgetController.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"

void UBWSOverlayWidgetController::BroadcastInitialValues()
{
    UBWSAttributeSet* const BWSAttributeSet = Cast<UBWSAttributeSet>(AttributeSet);
    if (!BWSAttributeSet) return;

    OnHealthChanged.Broadcast(BWSAttributeSet->GetHealth());
    OnMaxHealthChanged.Broadcast(BWSAttributeSet->GetMaxHealth());
}
