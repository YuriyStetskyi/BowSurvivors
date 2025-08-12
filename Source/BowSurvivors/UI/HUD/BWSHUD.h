// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BWSHUD.generated.h"

class UBWSUserWidget;
class UBWSOverlayWidgetController;
class UAbilitySystemComponent;
class UAttributeSet;

struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API ABWSHUD : public AHUD
{
	GENERATED_BODY()
public:
    UPROPERTY()
    UBWSUserWidget* OverlayWidget; 

    void InitOverlay(APlayerController* const PC, APlayerState* const PS, UAbilitySystemComponent* ASC, UAttributeSet* const AS);

protected:
    UBWSOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

private:
    UPROPERTY(EditAnywhere)
    TSubclassOf<UBWSUserWidget> OverlayWidgetClass;

    UPROPERTY()
    UBWSOverlayWidgetController* OverlayWidgetController;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UBWSOverlayWidgetController> OverlayWidgetControllerClass;
};
