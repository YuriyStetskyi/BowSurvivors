// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BWSHUD.generated.h"

class UBWSUserWidget;

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

protected:
    virtual void BeginPlay() override;


private:
    UPROPERTY(EditAnywhere)
    TSubclassOf<UBWSUserWidget> OverlayWidgetClass;

};
