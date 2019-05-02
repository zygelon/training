// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "ShootProjectile.generated.h"

UCLASS()
class TRAINING_API AShootProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShootProjectile();
	
	UFUNCTION(BlueprintCallable)
	void Init(float ProjectileSpeed, float Damage) { this->ProjectileSpeed = ProjectileSpeed; this->Damage = Damage; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnProjectileOVerlap(UPrimitiveComponent* overlappedComp,AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 BodyIndex,bool FromSweep, const FHitResult& HitResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="ShootProjectile")
	USphereComponent* Collision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ShootProjectile")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ShootProjectile")
	float ProjectileSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ShootProjectile")
	float Damage;
};
