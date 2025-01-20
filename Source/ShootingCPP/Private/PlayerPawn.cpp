// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/BoxComponent.h"
#include "Components/ArrowComponent.h"
#include "BulletActor.h"
#include "ShootingGameMode.h"
#include "Kismet/GameplayStatics.h"

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


	// 총구위치를 생성하고 루트에 붙이고 배치하고싶다.
	FirePositionComp = CreateDefaultSubobject<UArrowComponent>( TEXT("FirePositionComp") );
	FirePositionComp->SetupAttachment( RootComponent );
	FirePositionComp->SetRelativeLocationAndRotation( FVector( 0.0f, 0.0f, 100.0f ), FRotator( 90.0f, 0.0f, 0.0f ));

	// 오버랩 이벤트를 켠다.
	BoxComp->SetGenerateOverlapEvents(true);

	// 충돌 응답을 Query And Physics로 설정한다.
	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	// Object Type을 1번 채널(Player)로 설정한다.
	BoxComp->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);

	// 모든 채널을 충돌 응답 없음으로 설정한다.
	BoxComp->SetCollisionResponseToAllChannels(ECR_Ignore);

	// 에너미와는 충돌 이벤트 체크(Query)를 한다.
	BoxComp->SetCollisionResponseToChannel(ECC_GameTraceChannel3, ECR_Overlap);

	// WorldStatic( DeadZone )과 충돌 이벤트 체크를 한다.
	BoxComp->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);


}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	GM = Cast<AShootingGameMode>( GetWorld()->GetAuthGameMode() );
	// GameOverUI 숨기기, 마우스 커서 초기화, 게임 일시정지 해지, 인풋모드 게임으로 전환 등 초기화 설정
	GM->ShowGameOver( false );

	//// 게임을 일시 정지 상태로 만든다.
	//UGameplayStatics::SetGamePaused( GetWorld() , false );
	//
	//// 마우스 커서를 보이게 한다.
	//auto* pc = GetWorld()->GetFirstPlayerController();
	//pc->SetShowMouseCursor( false );
	//pc->SetInputMode( FInputModeGameOnly() );

	// 현재 체력을 최대 체력으로 설정한다.
	HP = MaxHP;
	
	// HP Bar를 갱신해준다.
	GM->SetHP( HP, MaxHP );
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//{
	//	// 오른쪽으로 이동하고 싶다.
	//	// P = P0 + v(방향 * Speed)t
	//	FVector p0 = GetActorLocation();
	//	FVector velocity = GetActorRightVector() * Speed;
	//	SetActorLocation( p0 + velocity * DeltaTime );
	//}

	{
		// 사용자의 입력에 따라 상하좌우로 이동하고 싶다
		
		// 좌우방향, 상하방향
		FVector dir = FVector( 0.0f, h, v );
		// dir의 길이를 1로 만들고 싶다.
		dir.Normalize();		

		// P = P0 + vt;
		FVector p0 = GetActorLocation();
		FVector velocity = dir * Speed;

		SetActorLocation( p0 + velocity * DeltaTime, true );
		//SetActorLocation( GetActorLocation() + dir.GetSafeNormal() * Speed * DeltaTime );
	}


}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// BindAxis ("연결할 Axis의 이름", 연결할 함수가 있는 클래스, 연결할 함수의 주소값 );
	PlayerInputComponent->BindAxis( TEXT("Horizontal"), this, &APlayerPawn::OnAxisHorizontal );
	PlayerInputComponent->BindAxis( TEXT("Vertical"), this, &APlayerPawn::OnAxisVertical );

	PlayerInputComponent->BindAction( TEXT("Fire"), IE_Pressed, this, &APlayerPawn::OnActionFire );

}

void APlayerPawn::OnAxisHorizontal( float value )
{
	h = value;
	//UE_LOG( LogTemp , Warning , TEXT( "H : %f" ), h );
}

void APlayerPawn::OnAxisVertical( float value )
{
	v = value;
	//UE_LOG( LogTemp , Warning , TEXT( "V : %f" ) , v );
}

void APlayerPawn::OnActionFire()
{
	// 클릭시 총알을 생성시켜 주고 싶다.
	FTransform FirePos = FirePositionComp->GetComponentTransform();

	GetWorld()->SpawnActor<ABulletActor>( BulletFactory, FirePos );

	UGameplayStatics::PlaySound2D( GetWorld(), FireSound );
}

void APlayerPawn::SetDamage( int32 damage )
{
	HP -= damage;

	// HP Bar 갱신
	GM->SetHP( HP, MaxHP );
}

