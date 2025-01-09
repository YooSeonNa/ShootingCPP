// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/BoxComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 충돌체 컴포넌트를 추가해서 Root컴포넌트로 설정
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	SetRootComponent( BoxComp );

	// 박스 Extent를 50으로 하고 싶다.
	BoxComp->SetBoxExtent(FVector( 50 ));


	// 메시 컴포넌트를 추가해서 Root컴포넌트에 Attach
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(BoxComp);
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

	{
		// 오른쪽으로 이동하고 싶다.
		// P = P0 + v(방향 * Speed)t
		FVector p0 = GetActorLocation();
		FVector velocity = GetActorRightVector() * Speed;
		SetActorLocation(p0 + velocity * DeltaTime);
	}




}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

