// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BWSWidgetController.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSWidgetController : public UObject
{
	GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    APlayerController* PlayerController;

    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    APlayerState* PlayerState;

    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    UAbilitySystemComponent* AbilitySystemComponent;

    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    UAttributeSet* AttributeSet;

};
