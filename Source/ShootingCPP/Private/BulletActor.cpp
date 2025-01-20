// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"
#include "Components/BoxComponent.h"
#include "EnemyActor.h"
#include "ShootingGameMode.h"
#include "Kismet/GameplayStatics.h"

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

	// 박스 컴포넌트의 콜리전 프리셋을 Bullet으로 설정한다.
	BoxComp->SetCollisionProfileName( TEXT("Bullet") ); 

	// 박스 컴포넌트의 충돌 오버랩 이벤트에 BulletOverlap 함수를 연결한다.
	BoxComp->OnComponentBeginOverlap.AddDynamic( this, &ABulletActor::OnBulletOverlap );
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

void ABulletActor::OnBulletOverlap( UPrimitiveComponent* OverlappedComponent , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex , bool bFromSweep , const FHitResult& SweepResult )
{
	// 충돌한 액터를 AEnemyActor 클래스로 변환해본다.
	AEnemyActor* enemy = Cast<AEnemyActor>(OtherActor);

	// 만일 캐스팅이 정상적으로 성공해서 포인터 enemy에 값이 있다면
	if( enemy != nullptr )
	{
		// 충돌한 액터를 제거한다.
		OtherActor->Destroy();

		// 현재 게임모드를 가져온다
		AGameModeBase* currentMode = GetWorld()->GetAuthGameMode();		

		// AShootingGameMode 클래스로 변환한다.
		AShootingGameMode* currentGameMode = Cast<AShootingGameMode>(currentMode);

		if( currentGameMode != nullptr )
		{
			// 게임 모드 베이스의 점수를 1점 추가한다.
			currentGameMode->AddScore( 1 );
		}

	}

	UGameplayStatics::PlaySound2D( GetWorld(), ExplosionSound );
	UGameplayStatics::SpawnEmitterAtLocation( GetWorld(), ExplosionVFX, GetActorTransform() );
	
	// 자기 자신도 제거한다.
	//this->Destroy();
	// Magazin Pool로 돌려보낸다
	SetActive( false );
}

void ABulletActor::SetActive( bool bValue )
{
	// 만약 bValue가 true라면 보이고, 충돌체도 활성화 시키고 싶다.
	MeshComp->SetVisibility( bValue );
	if( bValue )
	{
		BoxComp->SetCollisionEnabled( ECollisionEnabled::QueryAndPhysics );
	}
	// 그렇지 않다면 안보이고, 충돌체도 비활성화 시키고 싶다.
	else
	{		
		BoxComp->SetCollisionEnabled( ECollisionEnabled::NoCollision );
	}
}

