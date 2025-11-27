// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/BWSWidgetController.h"
#include "GameplayTagContainer.h"
#include "BWSOverlayWidgetController.generated.h"

class UBWSUserWidget;
struct FOnAttributeChangeData;

/* Struct that contains data for floating popup message widget. */
USTRUCT(BlueprintType)
struct FUIWidgetRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag MessageTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Message;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<UBWSUserWidget> MessageWidget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UTexture2D* Image = nullptr;

};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangedSignature, float, NewValue);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageWidgetRowSignature, FUIWidgetRow, Row);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOverlayAnimationPlayed);

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
    FOnAttributeChangedSignature OnHealthChanged;

    /* Broadcasted when Maximum Health is changed */
    UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
    FOnAttributeChangedSignature OnMaxHealthChanged;

    /* Broadcasted when current Money amount is changed */
    UPROPERTY(BlueprintAssignable, Category = "GAS | Attributes")
    FOnAttributeChangedSignature OnMoneyChanged;

    /* Broadcasted when popup message widget is created. */
    UPROPERTY(BlueprintAssignable, Category = "GAS | Messages")
    FMessageWidgetRowSignature MessageWidgetRowDelegate;

    /* Broadcasted when weapon stats animation is supposed to be played. */
    UPROPERTY(BlueprintAssignable, Category = "UI | Animations")
    FOnOverlayAnimationPlayed WeaponStatsAnimationPlayed;


protected:
    /* Data table with message widgets (popups) and required data to create them. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget Data")
    UDataTable* MessageWidgetDataTable;

    /* Returns Row of datatable that has matching tag column. */
    template <typename T>
    T* GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag);

};

template<typename T>
inline T* UBWSOverlayWidgetController::GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag)
{
    return DataTable->FindRow<T>(Tag.GetTagName(), TEXT(""));
}
