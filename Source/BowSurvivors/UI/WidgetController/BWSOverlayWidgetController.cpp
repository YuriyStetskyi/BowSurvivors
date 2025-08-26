// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "UI/WidgetController/BWSOverlayWidgetController.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "UI/Widgets/BWSUserWidget.h"

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
        BWSAttributeSet->GetHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
            {
                OnHealthChanged.Broadcast(Data.NewValue);
            });

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        BWSAttributeSet->GetMaxHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
            {
                OnMaxHealthChanged.Broadcast(Data.NewValue);
            });

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        BWSAttributeSet->GetMoneyAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
            {
                OnMoneyChanged.Broadcast(Data.NewValue);
            });
    
    UBWSAbilitySystemComponent* const ASC = Cast<UBWSAbilitySystemComponent>(AbilitySystemComponent);
    if (!ASC) return;

    ASC->EffectAssetTags.AddLambda([this](const FGameplayTagContainer& AssetTags) 
        {
            for (const FGameplayTag& Tag : AssetTags)
            {
                FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
                if (!Tag.MatchesTag(MessageTag)) continue;

                const FUIWidgetRow* const Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
                if (!Row) continue;
                MessageWidgetRowDelegate.Broadcast(*Row);
            }
        });
}