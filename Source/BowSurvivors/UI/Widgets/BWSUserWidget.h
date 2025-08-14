// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BWSUserWidget.generated.h"

/**
 *  Base class for all Widgets. Most important difference from UUserWidget - presence of WidgetController reference.
 */
UCLASS()
class BOWSURVIVORS_API UBWSUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    /* Methods that sets pointer of current widgets Widget Controller to a passed one, and calls WidgetControllerSet()*/
    UFUNCTION(BlueprintCallable)
    void SetWidgetController(UObject* InWidgetController);

    /* Stored pointer to current widgets Widget Controller. */
    UPROPERTY(BlueprintReadOnly)
    UObject* WidgetController;

protected:
    /* Blueprint Implementable event that should be called whenever widget controller is Set */
    UFUNCTION(BlueprintImplementableEvent)
    void WidgetControllerSet();

};
