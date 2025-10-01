// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "UI/HUD/BWSHUD.h"
#include "UI/Widgets/BWSUserWidget.h"
#include "UI/WidgetController/BWSOverlayWidgetController.h"
#include "UI/WidgetController/BWSWeaponWidgetController.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"
#include "Components/BWSWeaponComponent.h"

void ABWSHUD::InitOverlay(APlayerController* const PC, APlayerState* const PS, UAbilitySystemComponent* ASC, UAttributeSet* const AS)
{
    checkf(OverlayWidgetClass, TEXT("Overlay Widget Class unititialized, please fill out BP_BWSHUD"));
    checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class unitialized, please fill out BP_BWSHUD"));

    UWorld* const CurrentWorld = GetWorld();
    if (!CurrentWorld) return;

    UUserWidget* const Widget = CreateWidget<UUserWidget>(CurrentWorld, OverlayWidgetClass);
    if (!Widget) return;

    OverlayWidget = Cast<UBWSUserWidget>(Widget);
    if (!OverlayWidget) return;
    
    const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
    UBWSOverlayWidgetController* const WidgetController = GetOverlayWidgetController(WidgetControllerParams);

    OverlayWidget->SetWidgetController(WidgetController);
    WidgetController->BroadcastInitialValues();

    Widget->AddToViewport();
}

UBWSOverlayWidgetController* ABWSHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
    if (!OverlayWidgetController)
    {
        OverlayWidgetController = NewObject<UBWSOverlayWidgetController>(this, OverlayWidgetControllerClass);
        OverlayWidgetController->SetWidgetControllerParams(WCParams);
        OverlayWidgetController->BindCallbacksToDependencies();
    }

    return OverlayWidgetController;
}

UBWSWeaponWidgetController* ABWSHUD::GetWeaponWidgetController(const FWidgetControllerParams& WCParams, EWeaponSlot WeaponSlot)
{
    switch (WeaponSlot)
    {
    case EWeaponSlot::FisrtWeapon:
    {
        if (!FirstWeaponWidgetController)
        {
            FirstWeaponWidgetController = NewObject<UBWSWeaponWidgetController>(this, WeaponWidgetControllerClass);
            FirstWeaponWidgetController->SetWidgetControllerParams(WCParams);
            FirstWeaponWidgetController->BindCallbacksToDependencies();
        }
        return FirstWeaponWidgetController;
    }
    case EWeaponSlot::SecondWeapon:
    {
        if (!SecondWeaponWidgetController)
        {
            SecondWeaponWidgetController = NewObject<UBWSWeaponWidgetController>(this, WeaponWidgetControllerClass);
            SecondWeaponWidgetController->SetWidgetControllerParams(WCParams);
            SecondWeaponWidgetController->BindCallbacksToDependencies();
        }
        return SecondWeaponWidgetController;
    }
    case EWeaponSlot::ThirdWeaon: //maybe in the future as an upgrade or something
        break;
    case EWeaponSlot::None:
        break;
    default:
        break;
    }

    return nullptr;
}
