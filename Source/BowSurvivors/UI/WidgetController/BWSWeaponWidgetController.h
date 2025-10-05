// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/BWSWidgetController.h"
#include "BWSWeaponWidgetController.generated.h"

class UBWSWeaponAttributeInfo;

struct FWeaponAttributeInfo;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponAttributeChanged, const FWeaponAttributeInfo& , Info);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class BOWSURVIVORS_API UBWSWeaponWidgetController : public UBWSWidgetController
{
	GENERATED_BODY()
	
public:

    UPROPERTY(BlueprintAssignable)
    FOnWeaponAttributeChanged OnDamageChanged;

    virtual void BroadcastInitialValues() override;

    /*
        Should be called one time to bind appropriate functions to delegates responsible for attribute change.
        Should be overriden in inherited classes.
    */
    virtual void BindCallbacksToDependencies() override;

protected:

    UPROPERTY(EditDefaultsOnly, Category = "Attribute Info")
    UBWSWeaponAttributeInfo* WeaponAttributeInfo;

};
