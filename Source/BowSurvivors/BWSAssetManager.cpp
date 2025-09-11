// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "BWSAssetManager.h"
#include "BWSGameplayTags.h"

UBWSAssetManager& UBWSAssetManager::Get()
{
    check(GEngine);

    UBWSAssetManager* const BWSAssetManager = Cast<UBWSAssetManager>(GEngine->AssetManager);
    return *BWSAssetManager;
}

void UBWSAssetManager::StartInitialLoading()
{
    Super::StartInitialLoading();

    FBWSGameplayTags::InitializeNativeGameplayTags();
}
