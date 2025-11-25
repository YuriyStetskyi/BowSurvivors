// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "BWSGetMouseTargetData.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMouseTargetDataSignature, const FVector&, HitLocation);

/**
 *  Ability task that gets mouse cursor target data.
 */
UCLASS()
class BOWSURVIVORS_API UBWSGetMouseTargetData : public UAbilityTask
{
	GENERATED_BODY()

public:

    /* Returns instance of this task. Needed to have ability task working properly. */
    UFUNCTION(BlueprintCallable, meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "true"), Category = "Ability | Tasks")
    static UBWSGetMouseTargetData* GetMouseTargetData(UGameplayAbility* OwningAbility);

    /* Delegate broadcasts mouse target data when requested. */
    UPROPERTY(BlueprintAssignable)
    FMouseTargetDataSignature MouseTargetDataObtained;

protected:

    /* Runs when ability task is activated. */
    virtual void Activate() override;
};
