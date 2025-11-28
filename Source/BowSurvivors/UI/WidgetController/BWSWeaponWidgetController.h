// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/BWSWidgetController.h"
#include "BWSWeaponWidgetController.generated.h"

class UBWSWeaponAttributeInfo;

struct FWeaponAttributeInfo;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponAttributeChangedSignature, const FWeaponAttributeInfo& , Info);

/**
 *  Widget Controller  for a Weapon (each weapon has its own).
 */
UCLASS(BlueprintType, Blueprintable)
class BOWSURVIVORS_API UBWSWeaponWidgetController : public UBWSWidgetController
{
	GENERATED_BODY()
	
public:

    /* Delegate that is broadcasted when weapons attribute is changed. */
    UPROPERTY(BlueprintAssignable)
    FOnWeaponAttributeChangedSignature OnWeaponAttributeChanged;

    /* Broadcasts initial values for weapons attributes. */
    virtual void BroadcastInitialValues() override;

    /*
        Should be called one time to bind appropriate functions to delegates responsible for attribute change.
        Should be overriden in inherited classes.
    */
    virtual void BindCallbacksToDependencies() override;

protected:
    
    /* Stores all information about attributes (Tag, Name, Description etc.) */
    UPROPERTY(EditDefaultsOnly, Category = "Attribute Info")
    UBWSWeaponAttributeInfo* WeaponAttributeInfo;

};
