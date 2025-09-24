// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/BWSWidgetController.h"
#include "BWSWeaponStatsWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSWeaponStatsWidgetController : public UBWSWidgetController
{
	GENERATED_BODY()
	
public:

    virtual void BroadcastInitialValues() override;

    virtual void BindCallbacksToDependencies() override;
};
