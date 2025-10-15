// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/BWSWidgetController.h"
#include "BWSShopWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSShopWidgetController : public UBWSWidgetController
{
	GENERATED_BODY()
	
public:
    /* Runs delegates that hopefully update Initial data displayed in Shop Widget. */
    virtual void BroadcastInitialValues() override;

    /* Bind appropriate methods to delegates that are broadcasted on attribute change. */
    virtual void BindCallbacksToDependencies() override;
};
