// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManagerActor.h"
#include "Components/ArrowComponent.h"
#include "../Public/EnemyActor.h"

// Sets default values
AEnemyManagerActor::AEnemyManagerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>( TEXT("RootComp") );
	SetRootComponent( RootComp );

	Origin = CreateDefaultSubobject<UArrowComponent>( TEXT("Origin") );
	Origin->SetupAttachment( RootComponent );

	Origin->SetRelativeRotation( FRotator( -90.0f, 180.0f, 0.0f ) );
	//( Pitch = -90.000000 , Yaw = 180.000000 , Roll = 0.000000 )

}

// Called when the game starts or when spawned
void AEnemyManagerActor::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer( Handle, this, &AEnemyManagerActor::MakeEnemy, MakeTime, true );
}

void AEnemyManagerActor::EndPlay( const EEndPlayReason::Type EEndPlayReason )
{
	Super::EndPlay( EEndPlayReason );

	GetWorld()->GetTimerManager().ClearTimer( Handle );
}

// Called every frame
void AEnemyManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//// 1. 시간이 흐르다가
	//CurrentTime += DeltaTime;
	//
	//// 2. 만약에 현재시간이 생성시간을 초과하면
	//if( CurrentTime > MakeTime )
	//{
	//	// 3. Enemy를 스폰하고 싶다.
	//	MakeEnemy();
	//
	//	// 4. 현재시간을 0으로 초기화 하고 싶다.
	//	CurrentTime = 0.0f;
	//}
}

void AEnemyManagerActor::MakeEnemy()
{
	FTransform t = Origin->GetComponentTransform();
	GetWorld()->SpawnActor<AEnemyActor>( EnemyFactory , t );
}

