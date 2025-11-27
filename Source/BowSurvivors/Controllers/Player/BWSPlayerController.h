// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagContainer.h"
#include "BWSPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class ABWSPlayerCharacter;
class UEnhancedInputComponent;
class UBWSInputConfig;
class UBWSInputComponent;
class UBWSAbilitySystemComponent;

DECLARE_MULTICAST_DELEGATE(FOnWeaponStatsShow);

/**
 *  Default controller of player.
 */
UCLASS()
class BOWSURVIVORS_API ABWSPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    ABWSPlayerController(const FObjectInitializer& ObjectInitializer);

    /* Runs at game start */
    virtual void BeginPlay() override;

    /* Runs every frame */
    virtual void Tick(float DeltaTime) override;

    /* Delegate that is broadcasted when */
    FOnWeaponStatsShow OnWeaponStatsShow;
 
    /* Returns ECollisionChannel that Cursor is supposed to be collided with when deicding where to shoot projectile. */
    UFUNCTION(BlueprintCallable)
    ECollisionChannel GetCursorProjectionChannel() { return CursorProjectionChannel; }

protected:
    /* Called when controller possesses a pawn */
    virtual void OnPossess(APawn* ControlledPawn) override;

    /* Cached Enhanced Input Compoennt reference */
    UPROPERTY()
    UBWSInputComponent* BWSInputComponent;

    /* Default mapping context used for game */
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputMappingContext* DefaultMappingContext;

    /* Input action responsible for Moving */
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputAction* ActionMove;

    /* Input action responsible for Shooting */
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputAction* ActionShoot;

    /* Input action responsible for showing weapon stats */
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputAction* ActionShowWeaponStats;

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

    /* Show Weapon Stats. */
    void ShowWeaponStats();

#pragma region Mouse

    /* Rotates character to look at passed world location. Ignores vertical (Z) axis */
    void LookAtLocation(const FVector& LocationToLookAt);

    /* Current mouse location projected from cursor onto terrain. */
    FVector CurrentMouseLocation;

#pragma endregion 

    /* Runs when input of ability corresponding to a tag is pressed */
    void AbilityInputTagPressed(FGameplayTag InputTag);

    /* Runs when input of ability corresponding to a tag is released */
    void AbilityInputTagReleased(FGameplayTag InputTag);

    /* Runs when input of ability corresponding to a tag is held */
    void AbilityInputTagHeld(FGameplayTag InputTag);

    /* Should be called in Tick. Updates current mouse location in world. */
    void UpdateCurrrentMouseLocation();

    /* Input configuration. Has pairs of InputAction + Tag. */
    UPROPERTY(EditAnywhere, Category = "Input")
    UBWSInputConfig* InputConfig;

    /* Cached ASC reference for convenience purposes. */
    UPROPERTY()
    UBWSAbilitySystemComponent* BWSAbilitySystemComponent;

    /* Returns Ability System Component reference of controlled character. */
    UBWSAbilitySystemComponent* const GetASC();
};
