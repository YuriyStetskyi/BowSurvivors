// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "UI/HUD/BWSHUD.h"
#include "UI/Widgets/BWSUserWidget.h"
#include "UI/WidgetController/BWSOverlayWidgetController.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"

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

    Widget->AddToViewport();
}

UBWSOverlayWidgetController* ABWSHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
    if (!OverlayWidgetController)
    {
        OverlayWidgetController = NewObject<UBWSOverlayWidgetController>(this, OverlayWidgetControllerClass);
        OverlayWidgetController->SetWidgetControllerParams(WCParams);

        return OverlayWidgetController;
    }

    return OverlayWidgetController;
}
