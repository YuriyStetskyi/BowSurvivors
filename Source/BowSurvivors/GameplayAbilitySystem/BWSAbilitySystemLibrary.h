// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BWSAbilitySystemLibrary.generated.h"

class UBWSOverlayWidgetController;
class UBWSWeaponStatsWidgetController;

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

    UFUNCTION(BlueprintPure)
    static UBWSOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

    UFUNCTION(BlueprintPure)
    static UBWSWeaponStatsWidgetController* GetWeaponStatsWidgetController(const UObject* WorldContextObject);

};
