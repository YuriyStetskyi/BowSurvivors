// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/AbillityTasks/BWSGetMouseTargetData.h"
#include "Controllers/Player/BWSPlayerController.h"

UBWSGetMouseTargetData* UBWSGetMouseTargetData::GetMouseTargetData(UGameplayAbility* OwningAbility)
{
    UBWSGetMouseTargetData* MyObj = NewAbilityTask<UBWSGetMouseTargetData>(OwningAbility);

    return MyObj;
}

void UBWSGetMouseTargetData::Activate()
{
    Super::Activate();

    ABWSPlayerController* const PC = Cast<ABWSPlayerController>(Ability->GetCurrentActorInfo()->PlayerController.Get());
    if (!PC) return;

    FHitResult Hit;
    PC->GetHitResultUnderCursor(PC->GetCursorProjectionChannel(), true, Hit);

    MouseTargetDataObtained.Broadcast(Hit.Location);
}
