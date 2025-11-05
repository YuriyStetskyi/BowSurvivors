// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "BWSGetMouseTargetData.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMouseTargetDataSignature, const FVector&, HitLocation);

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSGetMouseTargetData : public UAbilityTask
{
	GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "true"), Category = "Ability | Tasks")
    static UBWSGetMouseTargetData* GetMouseTargetData(UGameplayAbility* OwningAbility);

    UPROPERTY(BlueprintAssignable)
    FMouseTargetDataSignature MouseTargetDataObtained;

protected:

    virtual void Activate() override;
};
