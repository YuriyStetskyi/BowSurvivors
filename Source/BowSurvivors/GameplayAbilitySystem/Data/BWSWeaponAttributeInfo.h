// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "BWSWeaponAttributeInfo.generated.h"

/* Struct containing information about Weapon Attribute. */
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
 *  Attribute information (tag, name, description, value - hidden).
 */
UCLASS()
class BOWSURVIVORS_API UBWSWeaponAttributeInfo : public UDataAsset
{
	GENERATED_BODY()
	
public:

    /* Finds attribute information from array via tag. */
    FWeaponAttributeInfo FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound = false) const;

    /* Array of attribute information. Can be parsed to find specific info about attribute via tag. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TArray<FWeaponAttributeInfo> AttributeInformation;

};
