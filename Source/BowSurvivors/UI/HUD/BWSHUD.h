// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BWSHUD.generated.h"

class UBWSUserWidget;
class UBWSOverlayWidgetController;
class UBWSWeaponWidgetController;
class UAbilitySystemComponent;
class UAttributeSet;

struct FWidgetControllerParams;

enum class EWeaponSlot : uint8;

/**
 *  Main HUD class.
 */
UCLASS()
class BOWSURVIVORS_API ABWSHUD : public AHUD
{
	GENERATED_BODY()
public:
    /* Reference to a main overlay widget. */
    UPROPERTY()
    UBWSUserWidget* OverlayWidget; 

    /* Method called when Overlay is initialized. Created to be used instead of BeginPlay for better timing control. */
    void InitOverlay(APlayerController* const PC, APlayerState* const PS, UAbilitySystemComponent* ASC, UAttributeSet* const AS);

    /* Method that either creates or returns created Overlay Widget Controller. */
    UBWSOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

    /* Method that either creates or returns created Weapon Widget Controller. */
    UBWSWeaponWidgetController* GetWeaponWidgetController(const FWidgetControllerParams& WCParams, EWeaponSlot WeaponSlot);


protected:

private:
    /* Type of overlay widget to be created. */
    UPROPERTY(EditAnywhere)
    TSubclassOf<UBWSUserWidget> OverlayWidgetClass;

    /* Overlay Widget Controller reference. */
    UPROPERTY()
    UBWSOverlayWidgetController* OverlayWidgetController;

    /* Type of overlay Widget Controller to be created. */
    UPROPERTY(EditAnywhere)
    TSubclassOf<UBWSOverlayWidgetController> OverlayWidgetControllerClass;

    /* Widget Controller for first weapon. */
    UPROPERTY()
    UBWSWeaponWidgetController* FirstWeaponWidgetController;

    /* Widget Controller for second weapon. */
    UPROPERTY()
    UBWSWeaponWidgetController* SecondWeaponWidgetController;

    /* Type of weapon Widget Controller to be created. */
    UPROPERTY(EditAnywhere)
    TSubclassOf<UBWSWeaponWidgetController> WeaponWidgetControllerClass;
};
