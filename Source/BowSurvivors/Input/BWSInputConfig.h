// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "BWSInputConfig.generated.h"

class UInputAction;

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
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TArray<FBWSInputAction> AbilityInputActions;

    const UInputAction* FindAbilityInputActionForGag(const FGameplayTag& InputTag, bool bLogNotFound = false) const;
};
