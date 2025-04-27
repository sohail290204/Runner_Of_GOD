// Fill out your copyright notice in the Description page of Project Settings.
#include "GrassLand1.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"


void AGrassLand1::BeginPlay()
{
    Super::BeginPlay();
    runspawner();
}

// Sets default values
AGrassLand1::AGrassLand1()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    static ConstructorHelpers::FClassFinder<AActor> ActorBP1(TEXT("/Game/BaseGround/Ground1.Ground1_C"));

    if (ActorBP1.Succeeded())
    {
        ActorToSpawn1 = ActorBP1.Class;
        UE_LOG(LogTemp, Warning, TEXT("Actor Fetched Successfully"));
       
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Actor Fetching error"));
    }
}

// Called when the game starts or when spawned

// Called every frame
void AGrassLand1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGrassLand1::runspawner() {

    ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    if (PlayerCharacter)
    {
        FVector PlayerLocation = PlayerCharacter->GetActorLocation();

        ActorLocationX = PlayerLocation.X;
        ActorLocationY = PlayerLocation.Y;
        ActorLocationZ = PlayerLocation.Z;

        PlayerLocationZ = PlayerLocation.Z - 200;
        PlayerLocationY = PlayerLocation.Y - 550;
        PlayerLocationX = PlayerLocation.X - 500;
        // UE_LOG(LogTemp, Warning, TEXT("Player Location: %f"), PlayerLocationX);
    }
    for (int i = 0; i < 15; i++) {

        FVector SpawnLocation1 = FVector(PlayerLocationX, PlayerLocationY, PlayerLocationZ);
        FRotator SpawnRotation1 = FRotator(0.0f, 0.0f, 0.0f);

        AActor* SpawnedFloor1 = GetWorld()->SpawnActor<AActor>(ActorToSpawn1, SpawnLocation1, SpawnRotation1);
        FVector FloorLocation1 = SpawnedFloor1->GetActorLocation();


        UE_LOG(LogTemp, Warning, TEXT("i : %d"), i);

        for (int j = 0; j < 50; j++) {

            FVector SpawnLocation2 = FVector(PlayerLocationX + 80, PlayerLocationY, PlayerLocationZ);
            FRotator SpawnRotation2 = FRotator(0.0f, 0.0f, 0.0f);

            AActor* SpawnedFloor2 = GetWorld()->SpawnActor<AActor>(ActorToSpawn1, SpawnLocation2, SpawnRotation2);
            FVector FloorLocation2 = SpawnedFloor2->GetActorLocation();
            PlayerLocationX = FloorLocation2.X;
            PlayerLocationY = FloorLocation2.Y;
            PlayerLocationZ = FloorLocation2.Z;
            UE_LOG(LogTemp, Warning, TEXT("j : %d"), j);
        }
        PlayerLocationX = FloorLocation1.X;
        PlayerLocationY = FloorLocation1.Y + 80;
        PlayerLocationZ = FloorLocation1.Z;
    }
}

