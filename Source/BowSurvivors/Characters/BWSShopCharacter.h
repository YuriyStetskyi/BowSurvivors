// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BWSBaseCharacter.h"
#include "BWSShopCharacter.generated.h"

class USphereComponent;
class UBillboardComponent;
class ABWSPlayerCharacter;

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API ABWSShopCharacter : public ABWSBaseCharacter
{
	GENERATED_BODY()

public:
    ABWSShopCharacter();

    UFUNCTION(BlueprintImplementableEvent)
    void PlayerEnteredRadius(ABWSPlayerCharacter* PlayerCharacter);

    UFUNCTION(BlueprintImplementableEvent)
    void PlayerLeftRadius(ABWSPlayerCharacter* PlayerCharacter);

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    USphereComponent* ShopAccessSphere;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    UBillboardComponent* ShopPopupBillboard;
    
private:
    void InitializeComponents();

    void BindOnOverlapCallbacks();

    UFUNCTION()
    void OnPlayerEnteredShopRadius(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnPlayerLeftShopRadius(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
