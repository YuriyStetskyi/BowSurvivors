// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BWSPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class ABWSPlayerCharacter;
class UEnhancedInputComponent;

/**
 * Default controller of player.
 */
UCLASS()
class BOWSURVIVORS_API ABWSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABWSPlayerController(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void OnPossess(APawn* ControlledPawn) override;

	/* Cached Player Character reference */
	UPROPERTY()
	ABWSPlayerCharacter* PlayerCharacter;

	/* Cached Enhanced Input Compoennt reference */
	UPROPERTY()
	UEnhancedInputComponent* EnhancedInputComponent;

	/* Default mapping context used for game */
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	/* Input action responsible for Moving */
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* ActionMove;

	/* Input action responsible for Shooting */
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* ActionShoot;

	/* Crosshair to be used in game */
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	UUserWidget* CrosshairWidget;

	/* Collision channel to hit when projecting ray to find world cursor locaiton */
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TEnumAsByte<ECollisionChannel> CursorProjectionChannel;

private:
	/* Setup Default Mapping context for enhanced input */
	void SetupEnhancedInput();

	/* Setup Input actions. Methods that run from actions should be located in character */
	void SetupInputActions(APawn* ControlledPawn);

	/* Set up all the cursor settings to work properly in game */
	void SetupCursor();

#pragma region Mouse

	/*
		Finds location projected from cursor onto world terrain.
		Argument passed is collision channel that should stop projection ray
	*/
	FVector FindProjectedMouseLocation(ECollisionChannel ProjectionCollisionChannel);

	/* Rotates character to look at passed world location. Ignores vertical (Z) axis */
	void LookAtLocation(const FVector& LocationToLookAt);

	/* Current mouse location projected from cursor onto terrain. */
	FVector CurrentMouseLocation;

#pragma endregion 

};
