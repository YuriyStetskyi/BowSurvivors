// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "BWSWeaponAttributeInfo.generated.h"

USTRUCT(BlueprintType)
struct FWeaponAttributeInfo
{
    GENERATED_BODY()

    FWeaponAttributeInfo();

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FGameplayTag AttributeTag;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FText AttributeName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FText AttributeDescription;

    UPROPERTY(BlueprintReadOnly)
    float AttributeValue;

};

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API UBWSWeaponAttributeInfo : public UDataAsset
{
	GENERATED_BODY()
	
public:

    FWeaponAttributeInfo FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound = false) const;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TArray<FWeaponAttributeInfo> AttributeInformation;

};
