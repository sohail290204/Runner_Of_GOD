// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RunnerBridge.generated.h"

UCLASS()
class ZOMBIEENDLESSRUNNER_API ARunnerBridge : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARunnerBridge();
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	float DelayDuration = 3.0f;

	void DelayedFunction();
	void DestroySelf();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* CollisionComponent;

	UPROPERTY(EditAnywhere)
	class USceneComponent* DefaultScene;

	//UFUNCTION()
	//void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	//UFUNCTION()
	//void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	FTimerHandle DelayTimerHandle;
};
