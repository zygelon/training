// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemySpawnController.h"

// Sets default values for this component's properties
UEnemySpawnController::UEnemySpawnController() : CurrentStage(0), EnemiesSpawned(0)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	

	// ...
}


void UEnemySpawnController::StartSpawnStage()
{
	GetWorld()->GetTimerManager().SetTimer(SpawnEnemyTimer, this,
		&UEnemySpawnController::SpawnEnemy, SpawnStages[CurrentStage].AfterEnemyDelay, true);
}

void UEnemySpawnController::SpawnEnemy()
{
	UE_LOG(LogTemp, Log, TEXT("SpawnEnemy!!"));
	EnemiesSpawned++;
	
	if (EnemiesSpawned >= SpawnStages[CurrentStage].SpawnEnemies.Num())
	{
		GetWorld()->GetTimerManager().ClearTimer(SpawnEnemyTimer);
		
	}
}

// Called when the game starts
void UEnemySpawnController::BeginPlay()
{
	Super::BeginPlay();

	// ...
	StartSpawnStage();
}




FORCEINLINE FEnemySpawnInfo& FEnemyStage::operator[](int32 index)
{
	if (index < SpawnEnemies.Num()) return SpawnEnemies[index];
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Index is out of range in EnemySpawnController"));
		return SpawnEnemies[0];
	}
}
