// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "BWSInputConfig.generated.h"

class UInputAction;

/* Input action struct. Links Input Action to Gameplay Tag. */
USTRUCT(BlueprintType)
struct FBWSInputAction
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly)
    const UInputAction* InputAction = nullptr;

    UPROPERTY(EditDefaultsOnly)
    FGameplayTag InputTag = FGameplayTag();
};

/**
 *  Stores all config related to input actions. Currently stores pairs of InputAction + Gameplay Tag and allows to Retrieve InputAction by Tag.
 */
UCLASS()
class BOWSURVIVORS_API UBWSInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
    /* Pair of InputAction + Gameplay Tag. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TArray<FBWSInputAction> AbilityInputActions;

    /* Retrieves Ability Action depending on tag provided. */
    const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound = false) const;
};
