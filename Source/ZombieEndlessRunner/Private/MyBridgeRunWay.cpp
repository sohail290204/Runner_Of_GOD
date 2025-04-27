// Fill out your copyright notice in the Description page of Project Settings.
#include "MyBridgeRunWay.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"
//#include "AMineCraftGameModeBase.h" 
#include <MineCraftGameModeBase.h>

// Sets default values
AMyBridgeRunWay::AMyBridgeRunWay()
{
	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	DefaultScene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	DefaultScene->SetupAttachment(RootComponent);

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetupAttachment(DefaultScene);
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AMyBridgeRunWay::OnOverlapBegin);
}

//void AMyBridgeRunWay::MyDelayedFunction()
//{
//	UE_LOG(LogTemp, Warning, TEXT("Function called after delay!"));
//}

// Called when the game starts or when spawned
void AMyBridgeRunWay::BeginPlay()
{
	Super::BeginPlay();
	//if (AMineCraftGameModeBase* GameMode = Cast<AMineCraftGameModeBase>(UGameplayStatics::GetGameMode(this)))
	//{
	//	//GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AActor::MyDelayedFunction, 3.0f, false);
	//	//GameMode->playerlcoation();
	//	UE_LOG(LogTemp, Warning, TEXT("Collision with BridgeRunWay detected and playerlcoation() called."));
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Error: Could not get GameMode."));
	//}
}

// Called every frame
void AMyBridgeRunWay::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AMyBridgeRunWay::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	/*if (!bHadRunned)
	{*/
		if (OtherActor && OtherActor != this)
		{
			if (AMineCraftGameModeBase* GameMode = Cast<AMineCraftGameModeBase>(UGameplayStatics::GetGameMode(this)))
			{
				GameMode->playerlocation();
				UE_LOG(LogTemp, Warning, TEXT("Collision with BridgeRunWay detected and playerlcoation() called."));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Error: Could not get GameMode."));
			}
		}
		else 
		{
			UE_LOG(LogTemp, Warning, TEXT("Error: Not an Actor."));
		}
	//	bHadRunned = true;
	//}
}

