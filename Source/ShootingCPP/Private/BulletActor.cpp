// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"
#include "Components/BoxComponent.h"

// Sets default values
ABulletActor::ABulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	BoxComp = CreateDefaultSubobject<UBoxComponent>( TEXT("BoxComp" ) );
	SetRootComponent( BoxComp );
	BoxComp->SetBoxExtent( FVector( 50 ) );

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>( TEXT("MeshComp") );
	MeshComp->SetupAttachment( RootComponent );

	// 생성자 도우미를 이용해서 에셋을 로드하고 싶다.
	ConstructorHelpers::FObjectFinder<UStaticMesh> TempMesh( TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'") );

	// 만약 로드한것이 성공했다면
	if( TempMesh.Succeeded() )
	{
		// 그 에셋을 컴포넌트에 넣어주고 싶다.
		MeshComp->SetStaticMesh( TempMesh.Object );
	}

	BoxComp->SetRelativeScale3D( FVector( 0.75f, 0.25f, 1.0f ));



}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	// 계속 앞으로 이동하고싶다.
	// P = P0 + vt;
	FVector p0 = GetActorLocation();
	FVector velocity = GetActorForwardVector() * Speed;
	float t = DeltaTime;
	SetActorLocation( p0 + velocity * t );
}

