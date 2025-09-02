// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "UI/WidgetController/BWSOverlayWidgetController.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"
#include "GameplayAbilitySystem/AttributeSet/BWSCharacterAttributeSet.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "UI/Widgets/BWSUserWidget.h"

void UBWSOverlayWidgetController::BroadcastInitialValues()
{
    UBWSCharacterAttributeSet* const BWSCharacterAttributeSet = Cast<UBWSCharacterAttributeSet>(AttributeSet);
    if (!BWSCharacterAttributeSet) return;

    OnHealthChanged.Broadcast(BWSCharacterAttributeSet->GetHealth());
    OnMaxHealthChanged.Broadcast(BWSCharacterAttributeSet->GetMaxHealth());
    OnMoneyChanged.Broadcast(BWSCharacterAttributeSet->GetMoney());
}

void UBWSOverlayWidgetController::BindCallbacksToDependencies()
{
    UBWSCharacterAttributeSet* const BWSCharacterAttributeSet = Cast<UBWSCharacterAttributeSet>(AttributeSet);
    if (!BWSCharacterAttributeSet) return;
   
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        BWSCharacterAttributeSet->GetHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
            {
                OnHealthChanged.Broadcast(Data.NewValue);
            });

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        BWSCharacterAttributeSet->GetMaxHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
            {
                OnMaxHealthChanged.Broadcast(Data.NewValue);
            });

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        BWSCharacterAttributeSet->GetMoneyAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
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