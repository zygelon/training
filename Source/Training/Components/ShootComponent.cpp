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
	//UE_LOG(LogTemp, Log, TEXT("Shoot"));
	for (FShootInfo Info : ShootInfos)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Owner = GetOwner();
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		

		FRotator SpawnRotation = GetOwner()->GetActorRotation();

		FVector SpawnLocation = GetOwner()->GetActorLocation() +
		GetOwner()->GetActorRotation().RotateVector(Info.Offset);

		SpawnRotation.Add(0.f, Info.Angle, 0.f);

		AShootProjectile* Projectile= GetWorld()->SpawnActor<AShootProjectile>(Info.ProjectileClass, SpawnLocation, SpawnRotation,SpawnParameters);

		if(Projectile)
			Projectile->Init(Info.ProjectileSpeed, Info.Damage);
		else
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red,"Shoot nullptr ERROR");

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

