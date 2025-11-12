// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Characters/BWSEnemyCharacter.h"
#include "GameplayAbilitySystem/BWSAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AttributeSet/BWSCharacterAttributeSet.h"
#include "Components/WidgetComponent.h"
#include "UI/Widgets/BWSUserWidget.h"

ABWSEnemyCharacter::ABWSEnemyCharacter()
    : EnemyLevel(1)
{
    InitializeComponents();
}

void ABWSEnemyCharacter::BeginPlay()
{
    Super::BeginPlay();

    InitializeAbilityActorInfo();

    UBWSUserWidget* const BWSHealthBarWidget = Cast<UBWSUserWidget>(HealthBarWidget->GetUserWidgetObject());
    if (!BWSHealthBarWidget) return;

    BWSHealthBarWidget->SetWidgetController(this);

    UBWSCharacterAttributeSet* const AS = Cast<UBWSCharacterAttributeSet>(AttributeSet);
    if (!AS) return;

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AS->GetHealthAttribute()).AddLambda(
        [this](const FOnAttributeChangeData& Data)
        {
            OnHealthChanged.Broadcast(Data.NewValue);
        });

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AS->GetMaxHealthAttribute()).AddLambda(
        [this](const FOnAttributeChangeData& Data)
        {
            OnMaxHealthChanged.Broadcast(Data.NewValue);
        });

    OnHealthChanged.Broadcast(AS->GetHealth());
    OnMaxHealthChanged.Broadcast(AS->GetMaxHealth());
}

void ABWSEnemyCharacter::InitializeAbilityActorInfo()
{
    AbilitySystemComponent->InitAbilityActorInfo(this, this);

    UBWSAbilitySystemComponent* const ASC = Cast<UBWSAbilitySystemComponent>(AbilitySystemComponent);
    if (!ASC) return;

    InitializeDefaultAttributes();

    ASC->AbilityActorInfoSet();
}

void ABWSEnemyCharacter::InitializeComponents()
{
    HealthBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthBarWidget"));
    HealthBarWidget->SetupAttachment(RootComponent);

    AbilitySystemComponent = CreateDefaultSubobject<UBWSAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AttributeSet = CreateDefaultSubobject<UBWSCharacterAttributeSet>(TEXT("AttributeSet"));
}
