// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BWSBaseCharacter.h"
#include "BWSShopCharacter.generated.h"

class USphereComponent;
class UBillboardComponent;
class ABWSPlayerCharacter;

/**
 *  Shopkeeper Character actor.
 */
UCLASS()
class BOWSURVIVORS_API ABWSShopCharacter : public ABWSBaseCharacter
{
	GENERATED_BODY()

public:
    ABWSShopCharacter();

    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
    UAttributeSet* GetAttributeSet() const { return AttributeSet; }

    /* Runs when player enters shop radius. Blueprint Implementable event.*/
    UFUNCTION(BlueprintImplementableEvent)
    void PlayerEnteredRadius(ABWSPlayerCharacter* PlayerCharacter);

    /* Runs when player leaves shop radius. Blueprint Implementable event.*/
    UFUNCTION(BlueprintImplementableEvent)
    void PlayerLeftRadius(ABWSPlayerCharacter* PlayerCharacter);

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    /* Radius in which player has access to the shop. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    USphereComponent* ShopAccessSphere;

    /* Billboard showing input required to open/close shop. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    UBillboardComponent* ShopPopupBillboard;
    
private:
    /* Initialize all the components. */
    void InitializeComponents();

    /* Bind callbacks to delegates broadcasted on shop radius overlap/overlapEnd. */
    void BindOnOverlapCallbacks();

    /* Callback to be bound to OnOverlap delegate of Shop Radius Sphere. */
    UFUNCTION()
    void OnPlayerEnteredShopRadius(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    /* Callback to be bound to OnOverlapEnd delegate of Shop Radius Sphere. */
    UFUNCTION()
    void OnPlayerLeftShopRadius(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
