// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Pawn.h"

// Sets default values
APlayerPawn::APlayerPawn()
{ 
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("PawnCollision"));
	SetRootComponent(PawnCollision);

	PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));
	PawnMesh->SetupAttachment(RootComponent);

	//CamSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CamSpringArm"));
	//CamSpringArm->SetupAttachment(RootComponent);

	PawnCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera"));
	//wnCamera->SetupAttachment(CamSpringArm);
	ShootComponent = CreateDefaultSubobject<UShootComponent>(TEXT("ShootComponent"));
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	ShootComponent->StartShooting();
}


// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//APlayerController* PlayerController= Cast<APlayerController>(GetController());
	/*
	bool Touch = false;
	float TouchX; float TouchY;
	if (PlayerController !=NULL)
	{
		PlayerController->GetInputTouchState(ETouchIndex::Touch1, TouchX, TouchY, Touch);
		if (Touch)
		{
			FVector2D TouchDeltaMove = FVector2D(TouchLocation.X - TouchX, TouchLocation.Y - TouchY)*TouchSensitive;
			UE_LOG(LogTemp, Log, TEXT("Touching in %f-%f"), TouchLocation.X-TouchX, TouchLocation.Y-TouchY);

			FVector NewLocation = GetActorLocation();
			NewLocation.X = FMath::Clamp(NewLocation.X + TouchDeltaMove.Y,-640.f,1100.f);
			NewLocation.Y = FMath::Clamp(NewLocation.Y - TouchDeltaMove.X, -500.f, 500.f);
			SetActorLocation(NewLocation);
			

			TouchLocation = FVector2D(TouchX, TouchY);
		}
	}*/

}

void APlayerPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindTouch(IE_Pressed, this, &APlayerPawn::OnTouchPressed);
	//InputComponent->BindTouch(IE_Released, this, &APlayerPawn::OnTouchRelease);
	InputComponent->BindTouch(IE_Repeat, this, &APlayerPawn::OnTouchMove);
}

void APlayerPawn::OnTouchPressed(ETouchIndex::Type Index, FVector Location)
{
	//UE_LOG(LogTemp, Log, TEXT("Touch Pressed: %s"),*TouchLocation.ToString());
	TouchLocation = FVector2D(Location);
	Touching = true;
}

void APlayerPawn::OnTouchMove(ETouchIndex::Type Index, FVector Location)
{
	//FVector2D TouchDeltaMove = FVector2D(TouchLocation.X - TouchX, TouchLocation.Y - TouchY)*TouchSensitive;
	//UE_LOG(LogTemp, Log, TEXT("Touching in %f-%f"), TouchLocation.X - TouchX, TouchLocation.Y - TouchY);

	//FVector NewLocation = GetActorLocation();
	//NewLocation.X = FMath::Clamp(NewLocation.X + TouchDeltaMove.Y, -640.f, 1100.f);
	//NewLocation.Y = FMath::Clamp(NewLocation.Y - TouchDeltaMove.X, -500.f, 500.f);
	FVector2D TouchDeltaMove = FVector2D(TouchLocation.X - Location.X, TouchLocation.Y - Location.Y);
	TouchDeltaMove *= TouchSensitive;
	//UE_LOG(LogTemp, Log, TEXT("%f, %f"), TouchLocation.X, Location.X);
	//UE_LOG(LogTemp, Log, TEXT("%f, %f"), TouchDeltaMove.X, TouchDeltaMove.Y);
	FVector NewLocation = GetActorLocation();
	NewLocation.X = FMath::Clamp(NewLocation.X+TouchDeltaMove.Y, -540.f, 1300.f);
	NewLocation.Y = FMath::Clamp(NewLocation.Y-TouchDeltaMove.X , -400.f, 400.f);

	SetActorLocation(NewLocation);

	TouchLocation = FVector2D(Location);


	//TouchLocation = FVector2D(TouchX, TouchY);
}

void APlayerPawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	PlayerController = Cast<APlayerController>(NewController);
}

void APlayerPawn::OnTouchRelease(ETouchIndex::Type Index, FVector Location)
{
	//UE_LOG(LogTemp, Log, TEXT("Touch Release: %s"),*TouchLocation.ToString());
	Touching = false;
}
