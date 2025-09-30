// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/BWSAbilitySystemLibrary.h"
#include "UI/WidgetController/BWSOverlayWidgetController.h"
#include "Controllers/Player/BWSPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Core/BWSPlayerState.h"
#include "UI/HUD/BWSHUD.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"

UBWSOverlayWidgetController* UBWSAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
    APlayerController* const PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
    if (!PC) return nullptr;

    ABWSHUD* const BWSHUD = Cast<ABWSHUD>(PC->GetHUD());
    if (!BWSHUD) return nullptr;

    ABWSPlayerState* const PS = PC->GetPlayerState<ABWSPlayerState>();
    if (!PS) return nullptr;

    UAbilitySystemComponent* const ASC = PS->GetAbilitySystemComponent();
    if (!ASC) return nullptr;

    UAttributeSet* const AS = PS->GetAttributeSet();
    if (!AS) return nullptr;

    return BWSHUD->GetOverlayWidgetController(FWidgetControllerParams(PC, PS, ASC, AS));
}