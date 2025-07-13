// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BWSBaseCharacter.h"
#include "BWSPlayerCharacter.generated.h"

struct FInputActionValue;

/**
 * 
 */
UCLASS()
class BOWSURVIVORS_API ABWSPlayerCharacter : public ABWSBaseCharacter
{
	GENERATED_BODY()

public:
	/* Move action */
	void Move(const FInputActionValue& InputActionValue);

	/* Shoot action */
	void Shoot(const FInputActionValue& InputActionValue);

protected:
	virtual void BeginPlay() override;

private:
	
};
