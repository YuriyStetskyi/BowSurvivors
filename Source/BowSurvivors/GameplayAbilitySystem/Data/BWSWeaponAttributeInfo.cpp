// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "GameplayAbilitySystem/Data/BWSWeaponAttributeInfo.h"

FWeaponAttributeInfo::FWeaponAttributeInfo()
    : AttributeTag(FGameplayTag())
    , AttributeName(FText())
    , AttributeDescription(FText())
    , AttributeValue(0.0f)
{
}

FWeaponAttributeInfo UBWSWeaponAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
    for (const FWeaponAttributeInfo& Info : AttributeInformation)
    {
        if (Info.AttributeTag == AttributeTag)
        {
            return Info;
        }
    }

    if (bLogNotFound)
    {
        UE_LOG(LogTemp, Error, TEXT("Can't find Info for AttributeTag [%s] on AttributeInfo [%s]. "), *AttributeTag.ToString(), *GetNameSafe(this));
    }

    return FWeaponAttributeInfo();
}
