// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "UI/WidgetController/BWSWidgetController.h"
#include "Controllers/Player/BWSPlayerController.h"
#include "Core/BWSPlayerState.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "GameplayAbilitySystem/BWSAttributeSet.h"

FWidgetControllerParams::FWidgetControllerParams()
    : PlayerController(nullptr)
    , PlayerState(nullptr)
    , AbilitySystemComponent(nullptr)
    , AttributeSet(nullptr)
{

}

FWidgetControllerParams::FWidgetControllerParams(APlayerController* const PC, APlayerState* const PS, UAbilitySystemComponent* ASC, UAttributeSet* const AS)
    : PlayerController(PC)
    , PlayerState(PS)
    , AbilitySystemComponent(ASC)
    , AttributeSet(AS)
{
    
}

void UBWSWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
    PlayerController = WCParams.PlayerController;
    PlayerState = WCParams.PlayerState;
    AbilitySystemComponent = WCParams.AbilitySystemComponent;
    AttributeSet = WCParams.AttributeSet;
}
