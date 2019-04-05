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

	CamSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CamSpringArm"));
	CamSpringArm->SetupAttachment(RootComponent);

	PawnCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera"));
	PawnCamera->SetupAttachment(CamSpringArm);


}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	APlayerController* PlayerController= Cast<APlayerController>(GetController());

	bool Touch = false;
	float TouchX; float TouchY;
	if (PlayerController !=NULL)
	{
		PlayerController->GetInputTouchState(ETouchIndex::Touch1, TouchX, TouchY, Touch);
		if (Touch)
			UE_LOG(LogTemp, Log, TEXT("Touching in %f-%f"), TouchX, TouchY);
	}

}

void APlayerPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindTouch(IE_Pressed, this, &APlayerPawn::OnTouchPressed);
	InputComponent->BindTouch(IE_Released, this, &APlayerPawn::OnTouchRelease);
}

void APlayerPawn::OnTouchPressed(ETouchIndex::Type Index, FVector Location)
{
	UE_LOG(LogTemp, Log, TEXT("Touch Pressed: %s"),*TouchLocation.ToString());
	TouchLocation = FVector2D(Location);
	Touching = true;
}

void APlayerPawn::OnTouchRelease(ETouchIndex::Type Index, FVector Location)
{
	UE_LOG(LogTemp, Log, TEXT("Touch Release: %s"),*TouchLocation.ToString());
	Touching = false;
}
