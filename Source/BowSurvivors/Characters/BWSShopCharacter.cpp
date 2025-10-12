// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Characters/BWSShopCharacter.h"
#include "Components/SphereComponent.h"


ABWSShopCharacter::ABWSShopCharacter()
{
    ShopAccessPopupRadius = CreateDefaultSubobject<USphereComponent>(TEXT("ShopAccessPopupRadius"));
}