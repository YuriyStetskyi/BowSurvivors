// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "BWSAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSAssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:
    static UBWSAssetManager& Get();

protected:
    virtual void StartInitialLoading() override;
};
