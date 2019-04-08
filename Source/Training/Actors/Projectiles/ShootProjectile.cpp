// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootProjectile.h"

// Sets default values
AShootProjectile::AShootProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("ProjectileCollision"));
	RootComponent = Collision;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collision);
	Mesh->SetCollisionProfileName("NoCollision");
}

// Called when the game starts or when spawned
void AShootProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShootProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(ProjectileSpeed*DeltaTime*FVector(1, 0,0));
	if (GetActorLocation().Size() > 3000.f)
		Destroy();
}

