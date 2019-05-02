// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyStage.h"

UEnemyStage::UEnemyStage() : StageDelay(1.f) , EnemiesSpawned(0)
{
	RandomSpawn.GenerateNewSeed();

	AddEnemy(FVector(600, 0.f + RandomSpawn.FRandRange(-300, 300), 0), 0.5f);
	AddEnemy(FVector(600, 100 + RandomSpawn.FRandRange(-300, 300), 0), 1.f,45.f);
	AddEnemy(FVector(600, 0.f + RandomSpawn.FRandRange(-300, 300), 0), 0.5f,-45.f);
}



void UEnemyStage::AddEnemy(/*AEnemyPawn* Enemy,*/ FVector position, float delay,float rotation)
{
	FEnemyInfo temp;
	temp.SpawnTransform = FTransform(FRotator(0, rotation+180.f,0),position);
	temp.EnemyDelay = delay;
	
	Enemies.Add(temp); 

}

void UEnemyStage::EnemiesSpawning()
{
	EnemySpawn();
	++EnemiesSpawned;
	if (!IsFull())
		GetWorld()->GetTimerManager().SetTimer(EnemySpawnTimer, this, &UEnemyStage::EnemiesSpawning, GetCurEnemy().EnemyDelay, false);
	
}

FEnemyInfo::FEnemyInfo()
{
	
	static ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(TEXT("Blueprint'/Game/Blueprints/Pawns/Enemies/BP_BaseEnemy.BP_BaseEnemy'"));
	if (ItemBlueprint.Object) {
		EnemyClass = (UClass*)ItemBlueprint.Object->GeneratedClass;; //= AEnemyPawn::StaticClass();
	}
}
