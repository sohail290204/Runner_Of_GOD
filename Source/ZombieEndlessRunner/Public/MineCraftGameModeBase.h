// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MineCraftGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIEENDLESSRUNNER_API AMineCraftGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public : 
	//int number = 10;
	//char variable[24] = "hello my name is sohail";
	
	
	float PlayerLocationX = 0;
	float PlayerLocationY = 0;
	float PlayerLocationZ = 0;
	//float SpawnPlayerLocation = 0;
	FVector SpawnedPlayerLocation= FVector(0.0f, 0.0f, 0.0f);
	FRotator PlayerRotation ;


	int PlayerRotationX;
	int PlayerRotationY;
	int PlayerRotationZ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector playerspwnlocation= FVector(0.0f, 0.0f, 0.0f);


	float ActorLocationX = 0;
	float ActorLocationY = 0;
	float ActorLocationZ = 0;
	float TargetLocationX = 0;



	//int CurrentLane = 0;

	AMineCraftGameModeBase();
	
	UFUNCTION(BlueprintCallable)
	void playerlocation();

	UFUNCTION(BlueprintCallable)
	void SpawnFloors();


	void SpawnHades();

	int  ii = 0;
	int iii = 0;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AActor> ActorToSpawn1;
	
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AActor> ActorToSpawn2;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AActor> ActorToSpawn3;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floor Array")
	TArray<TSubclassOf<AActor>> FloorActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstacle Array")
	TArray<TSubclassOf<AActor>> ObstacleActor;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hades")
	TSubclassOf<ACharacter> Hades;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hades")
	//TSubclassOf<ACharacter> Hades;
	//void loop();

	FVector TempLocation = FVector(PlayerLocationX, PlayerLocationY, PlayerLocationZ);
	//FVector SpawnLocation= FVector(PlayerLocationX, PlayerLocationY, PlayerLocationZ);
	FRotator SpawnRotation;
	FRotator StonerRotation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int numberTimes = 0;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int AxeNumber = 0;
	/*UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,bool bFromSweep, const FHitResult& SweepResult);*/

	/*UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Example")*/
	//TArray<int32> MyIntArray;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool InMainMenu = false;

	UFUNCTION(BlueprintCallable)
	void SpawnFloorsFromBp();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool Magnet = false;

	protected:
		virtual void BeginPlay() override;
};

