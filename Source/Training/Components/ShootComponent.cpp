// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootComponent.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UShootComponent::UShootComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.

	// ...
}


// Called when the game starts
void UShootComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UShootComponent::Shoot()
{
	UE_LOG(LogTemp, Log, TEXT("Shoot"));
	for (FShootInfo Info : ShootInfos)
	{
		FRotator SpawnRotation = GetOwner()->GetActorRotation();

		FVector SpawnLocation = GetOwner()->GetActorLocation() +
			Info.Offset.RotateAngleAxis(GetOwner()->GetActorRotation().Yaw,FVector(0.f,0.f,1.f));
		
		SpawnRotation.Add(0.f, Info.Angle, 0.f);

		GetWorld()->SpawnActor<AShootProjectile>(Info.ProjectileClass, SpawnLocation, SpawnRotation);
	}
}

void UShootComponent::StartShooting()
{
	GetWorld()->GetTimerManager().SetTimer(ShootingTimer, this, &UShootComponent::Shoot, ShootPeriod, true);
}

void UShootComponent::StopShooting()
{
	GetWorld()->GetTimerManager().ClearTimer(ShootingTimer);
}

