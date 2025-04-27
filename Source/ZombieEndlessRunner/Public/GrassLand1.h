// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrassLand1.generated.h"


UCLASS()
class ZOMBIEENDLESSRUNNER_API AGrassLand1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrassLand1();
	float PlayerLocationX = 0;
	float PlayerLocationY = 0;
	float PlayerLocationZ = 0;

	float ActorLocationX = 0;
	float ActorLocationY = 0;
	float ActorLocationZ = 0;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<AActor> ActorToSpawn1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Preview")
	class UInstancedStaticMeshComponent* PreviewInstancedMesh;

	UFUNCTION()
	void runspawner();
};
