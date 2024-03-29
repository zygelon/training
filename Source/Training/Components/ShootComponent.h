// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Actors/Projectiles/ShootProjectile.h"
#include "ShootComponent.generated.h"


USTRUCT(BlueprintType)
struct FShootInfo
{
	GENERATED_BODY()
		
	FShootInfo():Angle(0.f),Offset(0.f,40.f,0.f), ProjectileSpeed(1000.f),Damage(1.f){}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	TSubclassOf<AShootProjectile>ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	float ProjectileSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	float Damage;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Shooting")
	FVector Offset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
	float Angle;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRAINING_API UShootComponent : public UActorComponent
{
	GENERATED_BODY()
		
public:	
	// Sets default values for this component's properties
	UShootComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void Shoot();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	float ShootPeriod;

	

	FTimerHandle ShootingTimer;
public:	
	// Called every frame
	UFUNCTION(BlueprintCallable, Category = "Shooting")
	void StartShooting();

	UFUNCTION(BlueprintCallable, Category = "Shooting")
	void StopShooting();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	TArray<FShootInfo> ShootInfos;
};
