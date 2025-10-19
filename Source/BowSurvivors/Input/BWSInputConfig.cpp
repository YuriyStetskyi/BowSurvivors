// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Input/BWSInputConfig.h"

const UInputAction* UBWSInputConfig::FindAbilityInputActionForGag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
    for (const FBWSInputAction& Action : AbilityInputActions)
    {
        if (Action.InputAction && InputTag == Action.InputTag)
        {
            return Action.InputAction;
        }
    }

    if (bLogNotFound)
    {
        UE_LOG(LogTemp, Error, TEXT("Can't find AbilityInputAction for InputTag [%s], on InputConfig [%s]"), *InputTag.ToString(), *GetNameSafe(this));
    }

    return nullptr;
}
