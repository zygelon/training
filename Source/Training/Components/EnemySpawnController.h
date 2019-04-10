// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemySpawnController.generated.h"

USTRUCT(BlueprintType)
struct FEnemySpawnInfo{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	TSubclassOf<APawn>EnemyClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	FTransform SpawnTransform;
};

USTRUCT(BlueprintType)
struct FEnemyStage 
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	TArray<FEnemySpawnInfo>SpawnEnemies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	float StageDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	float AfterEnemyDelay;

	FORCEINLINE FEnemySpawnInfo& operator[](int32 index);

	
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRAINING_API UEnemySpawnController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemySpawnController();

	void StartSpawnStage();
	void SpawnEnemy();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	FTimerHandle ChangeStageTimer;
	FTimerHandle SpawnEnemyTimer;

	int32 EnemiesSpawned;
public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	int32 CurrentStage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enemies")
	TArray<FEnemyStage>SpawnStages;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemies")
	float StagesMinDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemies")
	float StagesMaxDelay;
		
};
