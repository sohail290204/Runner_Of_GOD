// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"
#include "Steve.generated.h"

UCLASS()
class ZOMBIEENDLESSRUNNER_API ASteve : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASteve();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	class UArrowComponent* AxeSpawnPoint;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AxeSpawnPoint")
	FVector AxeSpawnLocation;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AxeSpawnPoint")
	FRotator AxeSpawnRoration;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class USkeletalMeshComponent* SkeletonMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UCameraComponent* TppCamera;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UCameraComponent* FppCamera;


	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//void MoveForward(float value);
	void MoveRightLeft(float value);

	void getSpawnedPlayerLocation();
	void TimerForRun();
	void PlayerJump();


	UFUNCTION(BlueprintCallable)
	void PlayerDead();

	UFUNCTION(BlueprintCallable)
	void ThrowAxe();

	UFUNCTION(BlueprintImplementableEvent)
	void MakeHandEmpty();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool isrunning = true;
	//void SetPlayerLocation();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsFirstPerson;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bAxeInHandTrue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Health = 100;

	UFUNCTION(BlueprintCallable)
	void DamagePlayerBee();
	
	UFUNCTION(BlueprintCallable)
	void DamagePlayerDragon();

	UFUNCTION(BlueprintCallable)
	void DamegePlayerEnemy7();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float AxeHealth = 100;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bAxeThrown;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bStopRunning = true;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool PlayerAttackingWithAxe = false;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ActorLocationX ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ActorLocationXRight;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ActorLocationXLeft;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int currnetLane = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ActorLocationXUpdated;

	UPROPERTY(BlueprintReadWrite, Category = "Lane Array")
	TArray<float> LaneLocationArray;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ActorLocationY = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ActorLocationZ = 0;

	int TargetLocationX = 0;
	int PlayerLane = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ColumnJump = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool isjump = false;

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Actions")
	void SlideOverColumn();

	UFUNCTION(BlueprintImplementableEvent, Category = "Player regdoll active")
	void ActivateRegDoll();

	UFUNCTION(BlueprintImplementableEvent, Category = "Lane Switch TimeLine")
	void LaneSwitchTimeLine();


	UFUNCTION(BlueprintImplementableEvent, Category = "Make Jump False")
	void MakeJumpFalse();


	UFUNCTION(BlueprintImplementableEvent, Category = "Make Skin In Rage Mode")
	void MakeSkinColorRed();

	UFUNCTION(BlueprintImplementableEvent)
	void CoinsSave();

	UFUNCTION(BlueprintCallable)
	void slideJump();

	UFUNCTION(BlueprintCallable)
	void RageMode();

	UFUNCTION(BlueprintCallable)
	void WalkSpeed();


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bRageMode = false;


	UFUNCTION(BlueprintCallable)
	void CameraSwitch();

	UFUNCTION(BlueprintCallable)
	void SaveGame();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool JumpCalled = false;

	FVector SpawnedPlayerLocationInPlayer = FVector(0.0f, 0.0f, 0.0f);
	FVector TargetLocation = FVector(0, 0, 0);

	bool isPressed = false;
	bool bMoved = false;

	void makeragemodefalse();

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame")
	//TSubclassOf<USaveGame> UMySaveGame;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Axe")
	//TSubclassOf<AActor> AxeClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Axe")
	TArray<TSubclassOf<AActor>> AxeClass;

	// Spawn location for the axe
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Axe")
	//USceneComponent* AxeSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
	float Score;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
	float Coins;


	UFUNCTION(BlueprintCallable)
	void IncreaseCoin();

	UFUNCTION(BlueprintCallable)
	void HealthUpdate();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AxeSpawnNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool magnettrue;

	UFUNCTION(BlueprintCallable)
	void makemagnettrue();


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector spawnXlocation;

	UFUNCTION(BlueprintImplementableEvent)
	void spawsound();

protected:
	virtual void BeginPlay() override;


public:
	virtual void Tick(float DeltaTime) override;
	void SetPlayerLocation(FVector NewLocation);
};
