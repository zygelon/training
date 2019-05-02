// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootProjectile.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AShootProjectile::AShootProjectile():ProjectileSpeed()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("ProjectileCollision"));
	RootComponent = Collision;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collision);
	//Mesh->SetCollisionProfileName("NoCollision");
	//Collision->SetCollisionObjectType(ECC)
	//Collision->SetCollisionResponseToAllChannels(ECR_Ignore); 
	//Collision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	
}

// Called when the game starts or when spawned
void AShootProjectile::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner())
		Collision->IgnoreActorWhenMoving(GetOwner(), true);

	Collision->OnComponentBeginOverlap.AddDynamic(this, &AShootProjectile::OnProjectileOVerlap);
}

void AShootProjectile::OnProjectileOVerlap(UPrimitiveComponent* overlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 BodyIndex, bool FromSweep, const FHitResult& HitResult)
{
	
	UGameplayStatics::ApplyDamage(OtherActor, Damage,nullptr, this, UDamageType::StaticClass());

	Destroy();
}

// Called every frame
void AShootProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(ProjectileSpeed*DeltaTime*FVector(1, 0,0));
	//if (GetActorLocation().Size() > 3000.f)
	//	Destroy();
}

