// Fill out your copyright notice in the Description page of Project Settings.


#include "Hades.h"
#include "GameFramework/CharacterMovementComponent.h"
//FTimerHandle TimerHandle;
//FTimerHandle JumpTimerHandle;
// Sets default values
AHades::AHades()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SkeletonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Runner_Hades"));
	SkeletonMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("/Game/Hades/hades"));
	if (MeshAsset.Succeeded())
	{
		SkeletonMesh->SetSkeletalMesh(MeshAsset.Object);
	}
}


void AHades::TimerForRun()
{
	//AddMovementInput(GetActorForwardVector(), 1);
}

// Called when the game starts or when spawned
void AHades::BeginPlay()
{
	Super::BeginPlay();
	//GetWorldTimerManager().SetTimer(TimerHandle, this, &ASteve::TimerForRun, 0.01f, true);
}

// Called every frame
void AHades::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//GetCharacterMovement()->MaxWalkSpeed = CharRef->GetWorld->MaxWalkSpeed();
}

// Called to bind functionality to input
void AHades::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

