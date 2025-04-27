// Copyright Epic Games, Inc. All Rights Reserved.

#include "ZombieEndlessRunnerGameMode.h"
#include "ZombieEndlessRunnerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AZombieEndlessRunnerGameMode::AZombieEndlessRunnerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
