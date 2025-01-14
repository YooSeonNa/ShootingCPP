// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"
#include "Components/BoxComponent.h"
#include "PlayerPawn.h"

// Sets default values
AEnemyActor::AEnemyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 충돌체를 생성하고 루트컴포넌트로 지정하고 싶다.
	BoxComp = CreateDefaultSubobject<UBoxComponent>( TEXT("BoxComp") );
	SetRootComponent( BoxComp );

	// 외형을 생성하고 루트컴포넌트에 Attach 하고 싶다.
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>( TEXT("MeshComp") );
	MeshComp->SetupAttachment( RootComponent );


	// Collsion Presets을 Enemy 프리셋으로 변경하고 싶다.
	BoxComp->SetCollisionProfileName( TEXT("Enemy") );

	// 박스 컴포넌트의 BeginOverlap 델리게이트에 OnEnemyOverlap 함수를 연결한다.
	BoxComp->OnComponentBeginOverlap.AddDynamic( this, &AEnemyActor::OnEnemyOverlap );
}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();

	// 태어날때 방향을 정하고 ( 30%의 확률로 플레이어를 향해서 )
	// 아닐경우는 앞으로 이동하고 싶다.
	int32 randValue = FMath::RandRange( 1, 100 );
	if( randValue <= RandomRate )
	{
		// 플레이어를 타겟으로 하고싶다.
		auto* player = GetWorld()->GetFirstPlayerController()->GetPawn();		
		if( player != nullptr )
		{
			// 플레이어로 향하는 방향을 기억하고 싶다.
			Direction = player->GetActorLocation() - this->GetActorLocation();
			// 그 방향의 크기를 1로 하고 싶다.
			Direction.Normalize();
			// 그 방향을 기억하고 싶다.
		}		
	}
	// 그렇지 않을 경우는
	else
	{
		// 앞방향으로 이동하고 싶다.
		Direction = GetActorForwardVector();
	}
}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 태어나서 살아가면서 앞으로 이동하고 싶다.
	{
		// P = P0 + vt
		//SetActorLocation( GetActorLocation() + GetActorForwardVector() * Speed * DeltaTime );
	}

	// 확률 추첨을 통한 이동
	{
		// P = P0 + vt
		SetActorLocation( GetActorLocation() + Direction * Speed * DeltaTime );
	}
}

void AEnemyActor::OnEnemyOverlap( UPrimitiveComponent* OverlappedComponent , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex , bool bFromSweep , const FHitResult& SweepResult )
{
	// 충돌한 대상 액터를 APlayerPawn 클래스로 변환을 시도한다.
	APlayerPawn* player = Cast<APlayerPawn>( OtherActor );

	// 만일 캐스팅이 성공하면
	if( player != nullptr )
	{
		// 부딪힌 대상을 제거한다.
		OtherActor->Destroy();
	}

	// 자기 자신도 제거한다.
	Destroy();
}

