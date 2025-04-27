// Fill out your copyright notice in the Description page of Project Settings.
#include "MineCraftGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Math/UnrealMathUtility.h"


void AMineCraftGameModeBase::SpawnFloorsFromBp()
{
	for (int i = 0; i < 6; i++)
	{
		if (InMainMenu == true)
		{
			//UE_LOG(LogTemp, Warning, TEXT("SpawnBridge"));
			//SpawnFloors();
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("SpawnBridgefalse"));

		}
	}
}

void AMineCraftGameModeBase::BeginPlay() {
	Super::BeginPlay();

	playerlocation();



	UE_LOG(LogTemp, Warning, TEXT("Number %d"), AxeNumber);

}

AMineCraftGameModeBase::AMineCraftGameModeBase()
{
	// Set the default pawn class to your custom pawn
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Characters/MySteve"));
	if (PlayerPawnClassFinder.Succeeded())
	{
		DefaultPawnClass = PlayerPawnClassFinder.Class;
	}

	static ConstructorHelpers::FClassFinder<AActor> ActorBP1(TEXT("/Game/BaseGround/BpRunnerBridge.BpRunnerBridge_C"));
	if (ActorBP1.Succeeded())
	{
		//ActorToSpawn1 = ActorBP1.Class;
		FloorActor.Add(ActorBP1.Class);

	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Actor Fetching error"));
	}

	static ConstructorHelpers::FClassFinder<AActor> ActorBP4(TEXT("/Game/BaseGround/BpRunnerBridge1.BpRunnerBridge1_C"));
	if (ActorBP4.Succeeded())
	{
		//ActorToSpawn1 = ActorBP1.Class;
		FloorActor.Add(ActorBP4.Class);

	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Actor Fetching error"));
	}


	static ConstructorHelpers::FClassFinder<AActor> ActorBP2(TEXT("/Game/BaseGround/BpRunnerBridgeUp.BpRunnerBridgeUp_C"));
	if (ActorBP2.Succeeded())
	{
		//ActorToSpawn1 = ActorBP1.Class;
		FloorActor.Add(ActorBP2.Class);

	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Actor Fetching error"));
	}


	static ConstructorHelpers::FClassFinder<AActor> ActorBP3(TEXT("/Game/Bridge/BridgeCross.BridgeCross_C"));
	if (ActorBP3.Succeeded())
	{
		//ActorToSpawn1 = ActorBP1.Class;
		FloorActor.Add(ActorBP3.Class);

	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Actor Fetching error"));
	}

	static ConstructorHelpers::FClassFinder<AActor> ActorBP5(TEXT("/Game/Bridge/BridgeCross1.BridgeCross1_C"));
	if (ActorBP5.Succeeded())
	{
		//ActorToSpawn1 = ActorBP1.Class;
		FloorActor.Add(ActorBP5.Class);

	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Actor Fetching error"));
	}


	static ConstructorHelpers::FClassFinder<AActor> StoneBlock(TEXT("/Game/StonePillers/fire-beacon/FireBecon.FireBecon_C"));
	if (StoneBlock.Succeeded())
	{
		ObstacleActor.Add(StoneBlock.Class);
		//ActorToSpawn2 = StoneBlock.Class;
		//UE_LOG(LogTemp, Warning, TEXT("Stone Fetched Successfully"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Stone Fetching error"));
	}

	static ConstructorHelpers::FClassFinder<AActor> Column(TEXT("/Game/scandinavian-column/Column.Column_C"));
	if (StoneBlock.Succeeded())
	{
		ObstacleActor.Add(Column.Class);
		//ActorToSpawn3 = Column.Class;
		//UE_LOG(LogTemp, Warning, TEXT("Column Fetched Successfully"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Column Fetching error"));
	}


	static ConstructorHelpers::FClassFinder<AActor> HadesClass(TEXT("/Game/Characters/BpHades"));
	if (HadesClass.Succeeded())
	{
		Hades = HadesClass.Class;
	}
}

void AMineCraftGameModeBase::playerlocation()
{

	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	if (PlayerCharacter)
	{
		FVector PlayerLocation = PlayerCharacter->GetActorLocation();
		PlayerRotation = PlayerCharacter->GetActorRotation();
		//PlayerRotationY = PlayerRotation.Roll;
		//PlayerRotationX = PlayerRotation.Pitch;
		//PlayerRotationZ = PlayerRotation.Yaw;

		SpawnedPlayerLocation = PlayerLocation;

		ActorLocationX = PlayerLocation.X;
		ActorLocationY = PlayerLocation.Y;
		ActorLocationZ = PlayerLocation.Z;

		PlayerLocationZ = -1100.000046;
		PlayerLocationY = 13514.716617 + 3270;
		PlayerLocationX = 634.302307;
		// UE_LOG(LogTemp, Warning, TEXT("Player Location: %f"), PlayerLocationX); (X=634.302307,Y=13514.716617,Z=-1100.000046)
	//	SpawnHades();

	}


}


void AMineCraftGameModeBase::SpawnHades()
{

	FVector CharacterLocation = FVector(ActorLocationX, ActorLocationY + 1000, ActorLocationZ);
	ACharacter* SpawnedHades = GetWorld()->SpawnActor<ACharacter>(Hades, CharacterLocation, PlayerRotation);
	if (SpawnedHades)
	{
		UE_LOG(LogTemp, Warning, TEXT("HadesSpawned"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HadesSpawned failed"));

	}
}



void AMineCraftGameModeBase::SpawnFloors()
{
	/*numberTimes++;*/
	UE_LOG(LogTemp, Warning, TEXT("Floor Spawn: %d"), numberTimes);
	//(X=634.302307,Y=560.000000,Z=-1100.000000)
	FVector SpawnLocation = FVector(PlayerLocationX, PlayerLocationY, PlayerLocationZ);
	FVector StoneLocation = FVector(PlayerLocationX, PlayerLocationY, PlayerLocationZ);
	FVector ColumnLocation = FVector(PlayerLocationX, PlayerLocationY, PlayerLocationZ);


	int SpawnFloorChoose = FMath::RandRange(1, 10);
	int i;
	bool bspawnObstacle = false;
	if (SpawnFloorChoose > 5 && SpawnFloorChoose < 8 && numberTimes>5 && numberTimes + 1 != numberTimes)
	{
		i = 2;
		bspawnObstacle = false;
	}

	else if (SpawnFloorChoose > 1 && SpawnFloorChoose < 4 && numberTimes>5)
	{

		if (FMath::RandRange(1, 2) == 1)
		{

			i = 4;
		}
		else
		{
			i = 3;

		}
		bspawnObstacle = false;
	}
	else
	{
		if (FMath::RandRange(1, 2) == 1)
		{
			i = 1;
			UE_LOG(LogTemp, Warning, TEXT("Spawned Number 1"));
		}
		else
		{
			i = 0;

		}
		if (numberTimes > 2)
		{
			bspawnObstacle = true;
			//UE_LOG(LogTemp, Warning, TEXT("Obstracle spawn false"));
		}
	}

	TSubclassOf<AActor> FloorSelector = FloorActor[i];
	AActor* SpawnedFloor = GetWorld()->SpawnActor<AActor>(FloorSelector, SpawnLocation, SpawnRotation);

	SpawnedFloor->SetActorLocation(SpawnLocation);
	FVector SpawnedFloorLocation = SpawnedFloor->GetActorLocation();
	playerspwnlocation = FVector(SpawnedFloorLocation.X, SpawnedFloorLocation.Y, SpawnedFloorLocation.Z);



	if (bspawnObstacle)
	{
		int ChooseObstacle = FMath::RandRange(0, 4);
		if (ChooseObstacle == 2)
		{
			TSubclassOf<AActor> ObstacleSelector1 = ObstacleActor[0];
			FVector StoneLocation1 = FVector(StoneLocation.X + 280, StoneLocation.Y, StoneLocation.Z);
			AActor* SpawnedObstacle1 = GetWorld()->SpawnActor<AActor>(ObstacleSelector1, StoneLocation1, SpawnRotation);

			TSubclassOf<AActor> ObstacleSelector2 = ObstacleActor[1];
			FVector StoneLocation2 = FVector(StoneLocation.X, StoneLocation.Y, StoneLocation.Z);
			AActor* SpawnedObstacle2 = GetWorld()->SpawnActor<AActor>(ObstacleSelector2, StoneLocation2, SpawnRotation);
		}
		else
		{


			int ChooseObstacleLocation = FMath::RandRange(0, 2);
			if (ChooseObstacleLocation == 0 || ChooseObstacleLocation == 3)
			{
				TSubclassOf<AActor> ObstacleSelector = ObstacleActor[1];
				StoneLocation = FVector(StoneLocation.X + 230, StoneLocation.Y, StoneLocation.Z);
				AActor* SpawnedObstacle = GetWorld()->SpawnActor<AActor>(ObstacleSelector, StoneLocation, SpawnRotation);
			}
			else if (ChooseObstacleLocation == 1 || ChooseObstacleLocation == 4)
			{
				TSubclassOf<AActor> ObstacleSelector = ObstacleActor[0];
				AActor* SpawnedObstacle = GetWorld()->SpawnActor<AActor>(ObstacleSelector, SpawnLocation, SpawnRotation);
			}
			else
			{
				TSubclassOf<AActor> ObstacleSelector = ObstacleActor[0];
				StoneLocation = FVector(StoneLocation.X - 230, StoneLocation.Y, StoneLocation.Z);
				AActor* SpawnedObstacle = GetWorld()->SpawnActor<AActor>(ObstacleSelector, StoneLocation, SpawnRotation);
			}
		}

	}

	PlayerLocationY = PlayerLocationY + 3270;
	SpawnLocation = FVector(PlayerLocationX, PlayerLocationY, PlayerLocationZ);
	StoneLocation = FVector(PlayerLocationX, PlayerLocationY, PlayerLocationZ);
	ColumnLocation = FVector(StoneLocation.X, StoneLocation.Y, StoneLocation.Z);


}
