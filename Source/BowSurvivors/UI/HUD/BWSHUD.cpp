// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "UI/HUD/BWSHUD.h"
#include "UI/Widgets/BWSUserWidget.h"

void ABWSHUD::BeginPlay()
{
    Super::BeginPlay();

    UWorld* const CurrentWorld = GetWorld();
    if (!CurrentWorld) return;

    UUserWidget* const Widget = CreateWidget<UUserWidget>(CurrentWorld, OverlayWidgetClass);
    if (!Widget) return;

    Widget->AddToViewport();
}
