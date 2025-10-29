// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Weapons/BWSBaseWeapon.h"
#include "Characters/BWSPlayerCharacter.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AttributeSet/BWSWeaponAttributeSet.h"
#include "GameplayEffect.h"

// Sets default values
ABWSBaseWeapon::ABWSBaseWeapon()
    :WeaponLevel(1)
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    InitializeComponents();
}

UAbilitySystemComponent* ABWSBaseWeapon::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

FVector ABWSBaseWeapon::GetWeaponSocketLocation(FName SocketName)
{
    if (SocketName == "") // If no socket name specified - get it from PlayerCharacter who is HOPEFULLY owner
    {
        ABWSPlayerCharacter* const PlayerChar = Cast<ABWSPlayerCharacter>(GetOwner());
        if (!PlayerChar) return FVector();

        return SkeletalMeshComponent->GetSocketLocation(PlayerChar->ProjectileStartSocketName);
    }
    else
    {
        return SkeletalMeshComponent->GetSocketLocation(SocketName);
    }
}

// Called when the game starts or when spawned
void ABWSBaseWeapon::BeginPlay()
{
    Super::BeginPlay();

    InitializeAbilityActorInfo();
}

void ABWSBaseWeapon::Attack()
{

}

void ABWSBaseWeapon::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level)
{
    UAbilitySystemComponent* const ASC = GetAbilitySystemComponent();
    check(IsValid(ASC));

    check(GameplayEffectClass);

    const FGameplayEffectContextHandle EffectContext = ASC->MakeEffectContext();
    const FGameplayEffectSpecHandle EffectSpecHandle = ASC->MakeOutgoingSpec(GameplayEffectClass, Level, EffectContext);
    ASC->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data.Get(), ASC);
}

void ABWSBaseWeapon::InitializeComponents()
{
    SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
    SkeletalMeshComponent->SetupAttachment(GetRootComponent());
    SkeletalMeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    SkeletalMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    SkeletalMeshComponent->SetEnableGravity(false);

    /* Ability System Component */
    AbilitySystemComponent = CreateDefaultSubobject<UBWSAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AttributeSet = CreateDefaultSubobject<UBWSWeaponAttributeSet>(TEXT("AttributeSet"));
}

void ABWSBaseWeapon::InitializeAbilityActorInfo()
{
    // NOTE: in future owner should be a player - NOT WEAPON (first argument should be changed).
    AbilitySystemComponent->InitAbilityActorInfo(this, this);

    UBWSAbilitySystemComponent* const ASC = Cast<UBWSAbilitySystemComponent>(AbilitySystemComponent);
    if (!ASC) return;

    ASC->AbilityActorInfoSet();

    InitializeDefaultAttributes();
}

void ABWSBaseWeapon::InitializeDefaultAttributes()
{
    GenerateAttributes();
}

void ABWSBaseWeapon::GenerateAttributes()
{
    ApplyEffectToSelf(DefaultCoreWeaponAttributesInitializerEffect, 1.0f);
    ApplyEffectToSelf(DefaultDerivedWeaponAttributesInitializerEffect, 1.0f);
    ApplyEffectToSelf(DefaultWeaponScoreAttributesInitializerEffect, 1.0f);
}

// Called every frame
void ABWSBaseWeapon::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

