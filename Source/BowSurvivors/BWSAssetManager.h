// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "BWSAssetManager.generated.h"

/**
 *  Class that loads assets at a proper moment in programs lifetime. Currently only loads Native GameplayTags.
 */
UCLASS()
class BOWSURVIVORS_API UBWSAssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:
    /* Gets Asset Manager instance. */
    static UBWSAssetManager& Get();

protected:
    /* Main function that is used to load initial data of asset manager. */
    virtual void StartInitialLoading() override;
};
