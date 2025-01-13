// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManagerActor.h"
#include "Components/ArrowComponent.h"

// Sets default values
AEnemyManagerActor::AEnemyManagerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>( TEXT("RootComp") );
	SetRootComponent( RootComp );

	Origin = CreateDefaultSubobject<UArrowComponent>( TEXT("Origin") );
	Origin->SetupAttachment( RootComponent );

	//( Pitch = -90.000000 , Yaw = 180.000000 , Roll = 0.000000 )

}

// Called when the game starts or when spawned
void AEnemyManagerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

