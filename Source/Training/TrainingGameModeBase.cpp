// Fill out your copyright notice in the Description page of Project Settings.

#include "TrainingGameModeBase.h"

ATrainingGameModeBase::ATrainingGameModeBase()
{
	EnemySpawnController = CreateDefaultSubobject<UEnemySpawnController>(TEXT("EnemySpawnController"));
}
