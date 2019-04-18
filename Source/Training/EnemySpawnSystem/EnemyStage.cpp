// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyStage.h"

UEnemyStage::UEnemyStage() : StageDelay(1.f) , EnemiesSpawned(0)
{
	AddEnemy(FVector(300, -100, 0), 0.5f);
	AddEnemy(FVector(300, 100, 0), 1.f);
	AddEnemy(FVector(300, 0, 0), 0.5f);
}



void UEnemyStage::AddEnemy(/*AEnemyPawn* Enemy,*/ FVector position, float delay)
{
	FEnemyInfo temp;
	temp.SpawnTransform = FTransform(FRotator(0,0,0),position);
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
	
	static ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(TEXT("Blueprint'/Game/Blueprints/Pawns/Enemies/MyEnemyPawn.MyEnemyPawn'"));
	if (ItemBlueprint.Object) {
		EnemyClass = (UClass*)ItemBlueprint.Object->GeneratedClass;; //= AEnemyPawn::StaticClass();
	}
}