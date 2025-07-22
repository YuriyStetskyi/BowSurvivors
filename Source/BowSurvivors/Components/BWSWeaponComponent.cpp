// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Components/BWSWeaponComponent.h"
#include "Weapons/BWSBaseWeapon.h"
#include "Characters/BWSBaseCharacter.h"

// Sets default values for this component's properties
UBWSWeaponComponent::UBWSWeaponComponent()
    : CurrentWeapon(nullptr)
    , FirstWeapon(nullptr)
    , SecondWeapon(nullptr)
    , WeaponSocketName("WeaponSocket")
{
    PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts
void UBWSWeaponComponent::BeginPlay()
{
    Super::BeginPlay();

    SpawnWeapons();
    EquipWeaponSlot(EWeaponSlot::SecondWeapon);
}

void UBWSWeaponComponent::Attack()
{
    CurrentWeapon->Attack();
}

void UBWSWeaponComponent::EquipWeapon(ABWSBaseWeapon* const Weapon)
{
    if (!Weapon) return;
    CurrentWeapon = Weapon;

    UStaticMeshComponent* WeaponMesh = Weapon->GetMesh();
    if (!WeaponMesh) return;

    WeaponMesh->SetVisibility(true);
}

void UBWSWeaponComponent::HolsterWeapon(ABWSBaseWeapon* const Weapon)
{
    if (!Weapon) return;

    if (Weapon == CurrentWeapon) CurrentWeapon = nullptr;

    UStaticMeshComponent* WeaponMesh = Weapon->GetMesh();
    if (!WeaponMesh) return;

    WeaponMesh->SetVisibility(false);
}

void UBWSWeaponComponent::EquipWeaponSlot(EWeaponSlot WeaponToEquip)
{
    switch (WeaponToEquip)
    {
    case EWeaponSlot::FisrtWeapon:
    {
        HolsterWeapon(SecondWeapon);
        EquipWeapon(FirstWeapon);

        break;
    }
    case EWeaponSlot::SecondWeapon:
    {
        HolsterWeapon(FirstWeapon);
        EquipWeapon(SecondWeapon);

        break;
    }
    default:
    {
        CurrentWeapon = nullptr;
        break;
    }
    }
}

void UBWSWeaponComponent::SpawnWeapons()
{
    AActor* const Owner = GetOwner();
    if (!Owner) return;

    ABWSBaseCharacter* const BaseCharacter = Cast<ABWSBaseCharacter>(Owner);
    if (!BaseCharacter) return;

    USkeletalMeshComponent* const CharacterMesh = BaseCharacter->GetMesh();
    if (!CharacterMesh) return;

    FTransform SocketTransform = CharacterMesh->GetSocketTransform(WeaponSocketName);

    UWorld* const World = GetWorld();
    if (!World) return;

    FActorSpawnParameters SpawnParams;

    if (DefaultFirstWeapon)
    {
        FirstWeapon = World->SpawnActor<ABWSBaseWeapon>(DefaultFirstWeapon, SocketTransform);
        if (FirstWeapon) FirstWeapon->AttachToActor(Owner, FAttachmentTransformRules::KeepWorldTransform);
    }

    if (DefaultSecondWeapon)
    {
        SecondWeapon = World->SpawnActor<ABWSBaseWeapon>(DefaultSecondWeapon, SocketTransform);
        if (SecondWeapon) SecondWeapon->AttachToActor(Owner, FAttachmentTransformRules::KeepWorldTransform);
    }

}

// Called every frame
void UBWSWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

