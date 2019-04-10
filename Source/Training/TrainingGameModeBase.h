// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Components/EnemySpawnController.h"
#include "TrainingGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TRAINING_API ATrainingGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	ATrainingGameModeBase();
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemies")
	UEnemySpawnController* EnemySpawnController;
};
