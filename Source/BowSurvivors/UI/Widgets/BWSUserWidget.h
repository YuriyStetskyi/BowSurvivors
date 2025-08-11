// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BWSUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable)
    void SetWidgetController(UObject* InWidgetController);

    UPROPERTY(BlueprintReadOnly)
    UObject* WidgetController;

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void WidgetControllerSet();

};
