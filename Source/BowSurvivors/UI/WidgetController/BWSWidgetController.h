// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BWSWidgetController.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 *  Struct that stores Widget Controller Parameters. Those are: PlayerController, PlayerState, AbilitySystemComponent, AttributeSet.
 */
USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
    GENERATED_BODY()

    FWidgetControllerParams();
    FWidgetControllerParams(APlayerController* const PC, APlayerState* const PS, UAbilitySystemComponent* ASC, UAttributeSet* const AS);

    /* PlayerController instance reference. */
    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    APlayerController* PlayerController;

    /* PlayerState instance reference. */
    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    APlayerState* PlayerState;

    /* Main Component of Gameplay Ability System. */
    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    UAbilitySystemComponent* AbilitySystemComponent;

    /* Set of attributes. */
    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    UAttributeSet* AttributeSet;
};

/**
 *  Base WidgetController class. Every WidgetController should inherit this one.
 */
UCLASS()
class BOWSURVIVORS_API UBWSWidgetController : public UObject
{
	GENERATED_BODY()
public:
    /* Sets Widget Controller parameters to the ones passed in a struct */
    UFUNCTION(BlueprintCallable)
    void SetWidgetControllerParams(const FWidgetControllerParams& WCParams);

    /*  
        Should be called one time after initializing starting values of attributes.
        Should be overriden in inherited classes.
    */
    virtual void BroadcastInitialValues();

    /*  
        Should be called one time to bind appropriate functions to delegates responsible for attribute change.
        Should be overriden in inherited classes.
    */
    virtual void BindCallbacksToDependencies();

protected:
    /* PlayerController instance reference. */
    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    APlayerController* PlayerController;

    /* PlayerState instance reference. */
    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    APlayerState* PlayerState;

    /* Main Component of Gameplay Ability System. */
    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    UAbilitySystemComponent* AbilitySystemComponent;

    /* Set of attributes. */
    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    UAttributeSet* AttributeSet;

};
