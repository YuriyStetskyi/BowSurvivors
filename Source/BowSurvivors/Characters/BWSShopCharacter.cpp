// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Characters/BWSShopCharacter.h"
#include "Components/SphereComponent.h"
#include "Characters/BWSPlayerCharacter.h"
#include "Components/BillboardComponent.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AttributeSet/BWSShopAttributeSet.h"


ABWSShopCharacter::ABWSShopCharacter()
{
    InitializeComponents();
}

UAbilitySystemComponent* ABWSShopCharacter::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

void ABWSShopCharacter::BeginPlay()
{
    Super::BeginPlay();

    BindOnOverlapCallbacks();
}

void ABWSShopCharacter::InitializeComponents()
{
    ShopAccessSphere = CreateDefaultSubobject<USphereComponent>(TEXT("ShopAccessPopupRadius"));
    ShopAccessSphere->SetupAttachment(GetRootComponent());
    ShopAccessSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    ShopAccessSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

    ShopPopupBillboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("ShopPopupBillboard"));
    ShopPopupBillboard->SetupAttachment(GetRootComponent());
    ShopPopupBillboard->SetVisibility(false);
    ShopPopupBillboard->SetHiddenInGame(false);

    /* Ability System Component */
    AbilitySystemComponent = CreateDefaultSubobject<UBWSAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AttributeSet = CreateDefaultSubobject<UBWSShopAttributeSet>(TEXT("AttributeSet"));
}

void ABWSShopCharacter::BindOnOverlapCallbacks()
{
    ShopAccessSphere->OnComponentBeginOverlap.AddDynamic(this, &ABWSShopCharacter::OnPlayerEnteredShopRadius);
    ShopAccessSphere->OnComponentEndOverlap.AddDynamic(this, &ABWSShopCharacter::OnPlayerLeftShopRadius);
}

void ABWSShopCharacter::OnPlayerEnteredShopRadius(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    ABWSPlayerCharacter* const EnteredCharacter = Cast<ABWSPlayerCharacter>(OtherActor);
    if (!EnteredCharacter) return;

    PlayerEnteredRadius(EnteredCharacter);
}

void ABWSShopCharacter::OnPlayerLeftShopRadius(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    ABWSPlayerCharacter* const LeftCharacter = Cast<ABWSPlayerCharacter>(OtherActor);
    if (!LeftCharacter) return;

    PlayerLeftRadius(LeftCharacter);
}

