// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyBridgeRunWay.generated.h"

UCLASS()
class ZOMBIEENDLESSRUNNER_API AMyBridgeRunWay : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyBridgeRunWay();
	
	FTimerHandle TimerHandle;

	//UFUNCTION()
	//void MyDelayedFunction();

	//void DoOnceFunction();

protected:
	// Called when the game starts or when spawned


public:	
	UPROPERTY()
	bool bHadRunned = false;

	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* CollisionComponent;
	
	UPROPERTY(EditAnywhere)
	class USceneComponent* DefaultScene;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
};

