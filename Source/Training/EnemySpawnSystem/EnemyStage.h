// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/EnemyPawn.h"
#include "Components/ActorComponent.h"
#include "EnemyStage.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct FEnemyInfo {
	GENERATED_BODY()
	FEnemyInfo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	TSubclassOf<AEnemyPawn>EnemyClass;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	FTransform SpawnTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	float EnemyDelay;
};


UCLASS()
class TRAINING_API UEnemyStage :public UObject
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties

	UEnemyStage();
	//FORCEINLINE FEnemySpawnInfo& operator[](int32 index);
	//
protected:
	// Called when the game starts
	

	FTimerHandle EnemySpawnTimer;
	FRandomStream RandomSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EnemyStage")
	int32 EnemiesSpawned;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyStage")
	TArray<FEnemyInfo>Enemies;

	UFUNCTION(BlueprintCallable, Category = "EnemyStage")
	FORCEINLINE FEnemyInfo& GetCurEnemy() { return Enemies[EnemiesSpawned]; }
	

public:
	
	/*FORCEINLINE*/UFUNCTION(BlueprintCallable, Category = "EnemyStage")
	 bool IsFull() { return EnemiesSpawned >= Enemies.Num(); }
	
	/*FORCEINLINE*/UFUNCTION(BlueprintCallable, Category = "EnemyStage")
	void AddEnemy(/*AEnemyPawn* Enemy,*/ FVector position, float delay,float rotation=0.f);

	UFUNCTION(BlueprintCallable, Category = "EnemyStage")
	void EnemySpawn() { GetWorld()->SpawnActor<AEnemyPawn>(GetCurEnemy().EnemyClass, GetCurEnemy().SpawnTransform); }

	UFUNCTION(BlueprintCallable, Category = "EnemyStage")
	void EnemiesSpawning();

	//подумать
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyStage")
	float StageDelay;
	
};
