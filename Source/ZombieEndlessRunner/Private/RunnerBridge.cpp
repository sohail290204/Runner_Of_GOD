// Fill out your copyright notice in the Description page of Project Settings.
#include "RunnerBridge.h"

#include "Components/BoxComponent.h"
#include <MineCraftGameModeBase.h>
#include <Kismet/GameplayStatics.h>
#include "TimerManager.h"

// Sets default values
ARunnerBridge::ARunnerBridge()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultScene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	DefaultScene->SetupAttachment(RootComponent);

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetupAttachment(DefaultScene);

	//CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ARunnerBridge::OnOverlapBegin);
	//CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ARunnerBridge::OnOverlapEnd);
 //   CollisionComponent->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void ARunnerBridge::BeginPlay()
{
	Super::BeginPlay();
  //  UE_LOG(LogTemp, Warning, TEXT("End Overlap with "));
}

// Called every frame
void ARunnerBridge::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ARunnerBridge::DelayedFunction()
{
	//UE_LOG(LogTemp, Warning, TEXT("End Overlap with"));
	DestroySelf();
}

void ARunnerBridge::DestroySelf()
{
	// Check if the actor is valid before attempting to destroy it
	if (IsValid(this))
	{
		Destroy();
		//UE_LOG(LogTemp, Warning, TEXT("Actor destroyed."));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Actor is invalid and cannot be destroyed."));
	}
}

