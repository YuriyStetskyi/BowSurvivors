// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "UI/Widgets/BWSUserWidget.h"

void UBWSUserWidget::SetWidgetController(UObject* InWidgetController)
{
    WidgetController = InWidgetController;
    WidgetControllerSet();
}
