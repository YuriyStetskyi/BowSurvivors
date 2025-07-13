// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.


#include "Characters/BWSBaseCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ABWSBaseCharacter::ABWSBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	InitializeComponents();
}

// Called when the game starts or when spawned
void ABWSBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABWSBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABWSBaseCharacter::InitializeComponents()
{
	/* 
		Thing to remember:
		Default Root - CapsuleComponent (default component)
		SkeletalMesh - you can get via GetMesh(). Is attached to Root by default.
	*/

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
}
