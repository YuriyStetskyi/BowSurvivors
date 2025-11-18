// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BWSAbilitySystemLibrary.generated.h"

class UBWSOverlayWidgetController;
class UBWSWeaponWidgetController;
class UBWSWeaponComponent;

enum class EWeaponSlot : uint8;

/**
 *  Library with static functions for blueprint use.
 */
UCLASS()
class BOWSURVIVORS_API UBWSAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

    /* Returns OverlayWidgetController class reference. */
    UFUNCTION(BlueprintPure)
    static UBWSOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

    /* Returns WeaponWidgetController class reference. */
    UFUNCTION(BlueprintPure)
    static UBWSWeaponWidgetController* GetWeaponWidgetController(const UObject* WorldContextObject, EWeaponSlot WeaponSlot);

    /* Returns players PlayerWeaponComponent class reference. */
    UFUNCTION(BlueprintPure)
    static UBWSWeaponComponent* GetPlayerWeaponComponent(const UObject* WorldContextObject);
};
