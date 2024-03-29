// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ShootComponent.h"
#include "PlayerPawn.generated.h"


UCLASS()
class TRAINING_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnTouchRelease(ETouchIndex::Type,FVector);

	void OnTouchPressed(ETouchIndex::Type, FVector);

	void OnTouchMove(ETouchIndex::Type, FVector);

	virtual void PossessedBy(AController* NewController) override;

	UPROPERTY()
	APlayerController* PlayerController;

private:
	FVector2D TouchLocation;
	bool Touching;
	
	//UPROPERTY(
	//APlayerController* Controller;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controls")
	float TouchSensitive=2.5f;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Pawn")
	UBoxComponent* PawnCollision;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Pawn")
	UStaticMeshComponent* PawnMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shooting")
	UShootComponent* ShootComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pawn")
	UCameraComponent* PawnCamera;
};
