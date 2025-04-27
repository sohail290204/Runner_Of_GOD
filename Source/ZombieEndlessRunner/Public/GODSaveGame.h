// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GODSaveGame.generated.h"

/**
 *
 */
UCLASS()
class ZOMBIEENDLESSRUNNER_API UGODSaveGame : public USaveGame
{
	GENERATED_BODY()

public:


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float AllTimeHighScore;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int TotalCoins;

	UGODSaveGame();

};
