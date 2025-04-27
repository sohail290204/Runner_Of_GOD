// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Hades.generated.h"

UCLASS()
class ZOMBIEENDLESSRUNNER_API AHades : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHades();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	class UArrowComponent* AxeSpawnPoint;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SkeletonMesh")
	class USkeletalMeshComponent* SkeletonMesh;


	//class Steve* CharRef;

	void TimerForRun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
