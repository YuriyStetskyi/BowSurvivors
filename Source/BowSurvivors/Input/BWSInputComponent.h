// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "Input/BWSInputConfig.h"
#include "BWSInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:
    template<class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
    void BindAbilityActions(const UBWSInputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, HeldFuncType HeldFunc);


};

template<class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
inline void UBWSInputComponent::BindAbilityActions(const UBWSInputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, HeldFuncType HeldFunc)
{
    check(InputConfig);

    for (const FBWSInputAction& Action : InputConfig->AbilityInputActions)
    {
        if (Action.InputAction && Action.InputTag.IsValid())
        {
            if (PressedFunc)
            {
                BindAction(Action.InputAction, ETriggerEvent::Started, Object, PressedFunc, Action.InputTag);
            }

            if (ReleasedFunc)
            {
                BindAction(Action.InputAction, ETriggerEvent::Completed, Object, ReleasedFunc, Action.InputTag);
            }

            if (HeldFunc)
            {
                BindAction(Action.InputAction, ETriggerEvent::Triggered, Object, HeldFunc, Action.InputTag);
            }
        }
    }
}
