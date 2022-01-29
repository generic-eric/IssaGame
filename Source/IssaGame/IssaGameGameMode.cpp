// Copyright Epic Games, Inc. All Rights Reserved.

#include "IssaGameGameMode.h"
#include "IssaGamePlayerController.h"
#include "IssaGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AIssaGameGameMode::AIssaGameGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AIssaGamePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}