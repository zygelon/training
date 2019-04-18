// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemySpawnController.h"

// Sets default values for this component's properties
UEnemySpawnController::UEnemySpawnController() /*: CurrentStage(0), EnemiesSpawned(0)*/
{
	
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	/*StartSpawnStage();*/
	
	// ...
	
}


void UEnemySpawnController::StartSpawnStage()
{
	EnemyStages[0]->EnemiesSpawning();
	/*if (CurrentStage >= EnemyStages.Num())
	{
		UE_LOG(LogTemp, Log, TEXT("Stages is out of range %i enemies"), CurrentStage);
		return;
	}
	GetWorld()->GetTimerManager().SetTimer(SpawnEnemyTimer, this,
		&UEnemySpawnController::EnemySpawn, EnemyStages[CurrentStage].AfterEnemyDelay, true);*/
}
//
//void UEnemySpawnController::EnemySpawn()
//{
//	if (EnemiesSpawned >= EnemyStages[CurrentStage].SpawnEnemies.Num())
//	{
//		GetWorld()->GetTimerManager().ClearTimer(SpawnEnemyTimer);
//		UE_LOG(LogTemp, Log, TEXT("Spawned %i enemies"), EnemiesSpawned);
//		return;
//	}
//	//UClass* InClass, FVector const* Location = NULL, FRotator const* Rotation = NULL
//	GetWorld()->SpawnActor<AEnemyPawn>(EnemyStages[CurrentStage][EnemiesSpawned].EnemyClass, 
//		EnemyStages[CurrentStage][EnemiesSpawned].SpawnTransform );
//
//	EnemiesSpawned++;
//	
//	
//}

// Called when the game starts
void UEnemySpawnController::BeginPlay()
{
	Super::BeginPlay();

	
	EnemyStages.Add(NewObject<UEnemyStage>(this,UEnemyStage::StaticClass()));
	StartSpawnStage();
	// ...
	//StartSpawnStage();
}



//
//FORCEINLINE FEnemyInfo& FEnemyStage::operator[](int32 index)
//{
//	if (index < SpawnEnemies.Num()) return SpawnEnemies[index];
//	else
//	{
//		UE_LOG(LogTemp, Log, TEXT("Index is out of range in EnemySpawnController"));
//		return SpawnEnemies[0];
//	}
//}
