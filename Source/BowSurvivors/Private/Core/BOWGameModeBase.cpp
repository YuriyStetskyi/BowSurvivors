// Licensed under the MIT License.


#include "Core/BOWGameModeBase.h"
#include "Core/Controllers/BOWBaseController.h"
#include "Core/Characters/BOWPlayerCharacter.h"

ABOWGameModeBase::ABOWGameModeBase()
{
	PlayerControllerClass = ABOWBaseController::StaticClass();
	DefaultPawnClass = ABOWPlayerCharacter::StaticClass();
}