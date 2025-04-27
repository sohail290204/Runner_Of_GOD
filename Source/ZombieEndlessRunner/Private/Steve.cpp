// Fill out your copyright notice in the Description page of Project Settings.


#include "Steve.h"
//#include "AMineCraftGameModeBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include <MineCraftGameModeBase.h>
#include "Components/ArrowComponent.h"
#include <Kismet/GameplayStatics.h>
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
//#include "D:/unreal engine/UE_5.4/Engine/Plugins/VirtualProduction/TextureShare/Source/TextureShareCore/Private/Module/TextureShareCoreLogDefines.h"
//#include <Runtime/TraceLog/standalone_prologue.h>

FTimerHandle TimerHandle;
FTimerHandle JumpTimerHandle;
FTimerHandle RageModeTimerHandler;
FTimerHandle MakeMagnetTrueTimeEvent;

// Sets default values
ASteve::ASteve()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set the skeletonMesh in the character
	SkeletonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RunningPlayer"));
	SkeletonMesh->SetupAttachment(RootComponent);


	//Set steve model in the skeleton mesh 
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("/Game/BaseGround/kretos/source/Kratos1"));
	SkeletonMesh->SetRelativeLocation(FVector(0, 0, -19));
	SkeletonMesh->SetRelativeRotation(FRotator(0, 0, -90));
	if (MeshAsset.Succeeded())
	{
		SkeletonMesh->SetSkeletalMesh(MeshAsset.Object);
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("Skeleton Mesh Error"));
	}

	// Set the spring Arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.0f;

	//Set pring arm location and rotation
	SpringArm->SetRelativeLocation(FVector(0, 0, 70));
	SpringArm->SetRelativeRotation(FRotator(0, -10, 0));

	//Set and Attach the camera to the arm
	TppCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TppCamera"));
	TppCamera->SetupAttachment(SpringArm);
	TppCamera->bUsePawnControlRotation = true;

	FppCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FppCamera"));
	FppCamera->SetupAttachment(SkeletonMesh);

	bIsFirstPerson = true;
	TppCamera->SetActive(true);
	FppCamera->SetActive(false);



	AxeSpawnPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("AxeSpawnPoint"));
	AxeSpawnPoint->SetupAttachment(SkeletonMesh);
	AxeSpawnPoint->SetRelativeLocation(FVector(28.852397f, 9.617466f, 134.644520f)); // Adjust as needed (X=-28.852397,Y=9.617466,Z=134.644520)
	AxeSpawnPoint->SetRelativeRotation(FRotator(0.0f, -10.0f, 0.0f)); // Adjust as needed



	// SaveGame
	//UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

}

// Imput
void ASteve::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveRightLeft", this, &ASteve::MoveRightLeft);
	PlayerInputComponent->BindAction("Camera", IE_Pressed, this, &ASteve::CameraSwitch);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASteve::PlayerJump);
	PlayerInputComponent->BindAction("ThrowAxe", IE_Pressed, this, &ASteve::ThrowAxe);
	//PlayerInputComponent->BindAction("RageMode", IE_Pressed, this, &ASteve::RageMode);
}




//Move Left right and Swithc lanes
void ASteve::MoveRightLeft(float Value)
{
	if (Value == 0)
	{
		isPressed = false;
		bMoved = false;
	}
	else
	{
		isPressed = true;
	}

	if (isPressed && !bMoved)
	{
		ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
		if (PlayerCharacter)
		{


			FVector PlayerLocation = PlayerCharacter->GetActorLocation();
			//ActorLocationX = PlayerLocation.X;
			ActorLocationY = PlayerLocation.Y;
			ActorLocationZ = PlayerLocation.Z;

			if (Value < 0)
			{
				if (PlayerLane <= -1)
				{
					//	UE_LOG(LogTemp, Warning, TEXT("At the left most lane, Error"));
				}
				else
				{
					currnetLane = currnetLane + 1;
					UE_LOG(LogTemp, Warning, TEXT("Surrent lane %d"), currnetLane);
					ActorLocationXUpdated = LaneLocationArray[currnetLane];
					//TargetLocation = FVector(ActorLocationXUpdated, ActorLocationY, ActorLocationZ);
					LaneSwitchTimeLine();
					TargetLocation = FVector(ActorLocationXUpdated, ActorLocationY, ActorLocationZ);
					//SetPlayerLocation(TargetLocation);
					PlayerLane = PlayerLane - 1;
					spawsound();
				}

			}

			else if (Value > 0)
			{
				if (PlayerLane >= 1)
				{
					//UE_LOG(LogTemp, Warning, TEXT("At the right most lane, Error"));
				}
				else
				{
					currnetLane = currnetLane - 1;
					UE_LOG(LogTemp, Warning, TEXT("Surrent lane %d"), currnetLane);
					ActorLocationXUpdated = LaneLocationArray[currnetLane];;
					LaneSwitchTimeLine();
					TargetLocation = FVector(ActorLocationXUpdated, ActorLocationY, ActorLocationZ);
					//SetPlayerLocation(TargetLocation);
					PlayerLane = PlayerLane + 1;
					spawsound();
				}
			}
			bMoved = true;
			//	UE_LOG(LogTemp, Warning, TEXT("Player Lane %d"), PlayerLane);
		}
		else
		{
			//UE_LOG(LogTemp, Warning, TEXT("Player Not Fetched"));
		}
	}
}




//Call this function when space bar is pressed
void ASteve::PlayerJump()
{
	AActor* MyActor = GetOwner();

	// Call the BlueprintImplementableEvent directly
	//IMyInterface* MyBlueprintActor = Cast<IMyInterface>(MyActor);
	if (MyActor)
	{
		this->SlideOverColumn(); // Call the event directly
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Custom event not found"));
	}

}



// this is called from bp if slid is not possible this will run
void ASteve::slideJump()
{

	Super::Jump();
	//isjump = true;
	//GetWorld()->GetTimerManager().SetTimer(JumpTimerHandle, this, &ASteve::MakeJumpFalse, 1.5f, false);
	MakeJumpFalse();
	JumpCalled = false;

}


void ASteve::RageMode()
{
	bRageMode = true;
	WalkSpeed();
	MakeSkinColorRed();
	GetWorld()->GetTimerManager().SetTimer(RageModeTimerHandler, this, &ASteve::makeragemodefalse, 5.0f, false);
}


// Make RageModeFalse
void ASteve::makeragemodefalse()
{
	UE_LOG(LogTemp, Error, TEXT("Rgemodedone"));
	bRageMode = false;
	WalkSpeed();

}


//WalkSpeed
void ASteve::WalkSpeed()
{
	if (bRageMode)
	{
		float speed = GetCharacterMovement()->MaxWalkSpeed;
		GetCharacterMovement()->MaxWalkSpeed = speed + 800.0f;
	}
	else if (!bRageMode)
	{

		float speed = GetCharacterMovement()->MaxWalkSpeed;
		GetCharacterMovement()->MaxWalkSpeed = speed - 800.0f;
		UE_LOG(LogTemp, Warning, TEXT("Speed Decreased"));
	}

}


// Camera Switch
void ASteve::CameraSwitch()
{
	bIsFirstPerson = !bIsFirstPerson;

	if (bIsFirstPerson)
	{
		FppCamera->SetActive(true);
		TppCamera->SetActive(false);
	}
	else
	{
		FppCamera->SetActive(false);
		TppCamera->SetActive(true);
	}

}

void ASteve::SaveGame()
{


}


// Player Dead
void ASteve::PlayerDead()
{
	GetCharacterMovement()->DisableMovement();

	USkeletalMeshComponent* SkeletalMesh = GetMesh();
	if (SkeletalMesh)
	{
		SkeletalMesh->SetSimulatePhysics(true);
		SkeletalMesh->SetCollisionProfileName(TEXT("Ragdoll"));
	}
	DetachFromControllerPendingDestroy();
	UE_LOG(LogTemp, Warning, TEXT("Player Dead Function"));
	bStopRunning = false;
	ActivateRegDoll();

}

void ASteve::ThrowAxe()
{
	if (AxeHealth > 50)
	{

		AMineCraftGameModeBase* GameMode = Cast<AMineCraftGameModeBase>(UGameplayStatics::GetGameMode(this));
		if (GameMode)
		{
			AxeSpawnNumber = GameMode->AxeNumber;
			UE_LOG(LogTemp, Log, TEXT("Current Score from GameMode: %d"), AxeSpawnNumber);
		}

		else
		{
			UE_LOG(LogTemp, Warning, TEXT("GameMode is null or not of type AYourGameMode!"));
		}



		if (bAxeInHandTrue && !bAxeThrown)
		{
			if (!AxeClass.IsValidIndex(AxeSpawnNumber))
			{
				UE_LOG(LogTemp, Error, TEXT("AxeClass is not assigned in the character blueprint!"));
				return;
			}

			TSubclassOf<AActor> SelectedAxeClass = AxeClass[AxeSpawnNumber];
			if (!SelectedAxeClass)
			{
				UE_LOG(LogTemp, Warning, TEXT("SelectedAxeClass is null!"));
				return;
			}

			FVector SpawnLocation = AxeSpawnLocation;
			FRotator SpawnRotation = AxeSpawnRoration;
			AActor* SpawnedAxe = GetWorld()->SpawnActor<AActor>(SelectedAxeClass, SpawnLocation, SpawnRotation);

			if (SpawnedAxe)
			{
				UE_LOG(LogTemp, Warning, TEXT("Axe spawned successfully!"));
				bAxeThrown = true; // Update the flag
				MakeHandEmpty();   // Call your custom logic to handle the state
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to spawn axe!"));
			}
		}
	}
}

void ASteve::DamagePlayerBee()
{

	//float StartValue = Health;
	//float EndValue = Health - 20;
	//float Alpha = 1;
	//float InterpolatedValue = FMath::Lerp(StartValue, EndValue, Alpha);
	Health = Health - 20;
	if (Health <= 0)
	{
		PlayerDead();
	}
}

void ASteve::DamagePlayerDragon()
{
	//UE_LOG(LogTemp, Error, TEXT("PlayerDamage"));
	//float StartValue = Health;
	//float EndValue = Health - 30;
	//float Alpha = 1;
	//float InterpolatedValue = FMath::Lerp(StartValue, EndValue, Alpha);
	Health = Health - 30;
	if (Health <= 0)
	{
		PlayerDead();
	}
}

void ASteve::DamegePlayerEnemy7()
{
	Health = Health - 30;
	if (Health <= 0)
	{
		PlayerDead();
	}

}


//Get the location of the player spawned
void ASteve::getSpawnedPlayerLocation()
{
	if (AMineCraftGameModeBase* GameMode = Cast< AMineCraftGameModeBase>(GetWorld()->GetAuthGameMode()))
	{
		SpawnedPlayerLocationInPlayer = GameMode->SpawnedPlayerLocation;
	}
}

//Continues Running
void ASteve::TimerForRun()
{
	if (bStopRunning)
	{

		//UE_LOG(LogTemp, Warning, TEXT("runniong"));
		AddMovementInput(GetActorForwardVector(), 1);

		float speed = GetCharacterMovement()->MaxWalkSpeed;
		GetCharacterMovement()->MaxWalkSpeed = speed + 0.05;
		float animrate = SkeletonMesh->GlobalAnimRateScale ;
		SkeletonMesh->GlobalAnimRateScale = animrate + 0.000001;
		Score = Score + 0.1;
		//UE_LOG(LogTemp, Error, TEXT("Score Increasing"));
	}

}

void ASteve::IncreaseCoin()
{
	CoinsSave();
	Coins++;
}

void ASteve::HealthUpdate()
{
	Health += 30;
	if (Health > 100)
	{
		Health = 100;
	}
}

void ASteve::makemagnettrue()
{
	if (!magnettrue)
	{
		magnettrue = true;
		GetWorld()->GetTimerManager().SetTimer(MakeMagnetTrueTimeEvent, this, &ASteve::makemagnettrue, 5.0f, false);
	}
	else
	{
		magnettrue = false;
	}
}

// Begin play
void ASteve::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ASteve::TimerForRun, 0.01f, true);
	getSpawnedPlayerLocation();
	//WalkSpeed();


	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (PlayerCharacter)
	{

		FVector PlayerLocation = PlayerCharacter->GetActorLocation();
		ActorLocationX = PlayerLocation.X;
		ActorLocationY = PlayerLocation.Y;
		ActorLocationZ = PlayerLocation.Z;

		ActorLocationXRight = ActorLocationX + 230;
		ActorLocationXLeft = ActorLocationX - 230;

		LaneLocationArray.Add(ActorLocationXLeft);
		LaneLocationArray.Add(ActorLocationX);
		LaneLocationArray.Add(ActorLocationXRight);
	}






}


//Called every frame
void ASteve::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	AMineCraftGameModeBase* GameMode = Cast<AMineCraftGameModeBase>(UGameplayStatics::GetGameMode(this));
	if (GameMode)
	{
		spawnXlocation = GameMode->playerspwnlocation;
		//UE_LOG(LogTemp, Log, TEXT("Current Score from GameMode: %d"), spawnXlocation);
	}
}


//Lane Changing
void ASteve::SetPlayerLocation(FVector NewLocation)
{
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	if (PlayerCharacter)
	{
		PlayerCharacter->SetActorLocation(NewLocation);

	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Failed to find player character."));
	}
}

