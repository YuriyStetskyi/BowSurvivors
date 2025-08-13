// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BWSWidgetController.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
    GENERATED_BODY()

    FWidgetControllerParams();
    FWidgetControllerParams(APlayerController* const PC, APlayerState* const PS, UAbilitySystemComponent* ASC, UAttributeSet* const AS);

    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    APlayerController* PlayerController;

    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    APlayerState* PlayerState;

    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    UAbilitySystemComponent* AbilitySystemComponent;

    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    UAttributeSet* AttributeSet;
};

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSWidgetController : public UObject
{
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    void SetWidgetControllerParams(const FWidgetControllerParams& WCParams);

    virtual void BroadcastInitialValues();

    virtual void BindCallbacksToDependencies();

protected:
    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    APlayerController* PlayerController;

    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    APlayerState* PlayerState;

    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    UAbilitySystemComponent* AbilitySystemComponent;

    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    UAttributeSet* AttributeSet;

};
