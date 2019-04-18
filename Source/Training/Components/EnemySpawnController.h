// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemySpawnSystem/EnemyStage.h"
#include "EnemySpawnController.generated.h"
/*
USTRUCT(BlueprintType)
struct FEnemyInfo{
	GENERATED_BODY()
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	TSubclassOf<AEnemyPawn>EnemyClass=AEnemyPawn::StaticClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	FTransform SpawnTransform;

	
};

USTRUCT(BlueprintType)
struct FEnemyStage 
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	TArray<FEnemyInfo>SpawnEnemies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	float StageDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	float AfterEnemyDelay;

	FORCEINLINE FEnemyInfo& operator[](int32 index);

	
};*/


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRAINING_API UEnemySpawnController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	
	UEnemySpawnController();

	void StartSpawnStage();
	
	
protected:
	
	virtual void BeginPlay() override;

	FTimerHandle ChangeStageTimer;
	

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	int32 CurrentStage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enemies")
	TArray<UEnemyStage*>EnemyStages;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemies")
	float StagesMinDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemies")
	float StagesMaxDelay;
		
};
