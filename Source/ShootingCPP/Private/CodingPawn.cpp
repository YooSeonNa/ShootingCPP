// Fill out your copyright notice in the Description page of Project Settings.


#include "CodingPawn.h"

// Sets default values
ACodingPawn::ACodingPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACodingPawn::BeginPlay()
{
	Super::BeginPlay();

	// 헬로월드 / 로그
	UE_LOG( LogTemp , Warning , TEXT( "Hello World" ) );

	GEngine->AddOnScreenDebugMessage( 0 , 10 , FColor::Cyan , TEXT( "Hello World" ) );

	// 자료형
	// 정수, 실수, 논리, 문자열 자료형을 가장 많이 쓴다.
	// int 형의 경우 int32로 사용한다.

	UE_LOG( LogTemp , Warning , TEXT( "%d" ) , Number );
	UE_LOG( LogTemp , Warning , TEXT( "%.2f" ) , Distance );
	UE_LOG( LogTemp , Warning , TEXT( "%d" ) , bGood );

	// 문자열
	// FString : 문자열을 조합해서 생성, 주로 사용하는 문자열 자료형
	// FText,	FName
	UE_LOG( LogTemp , Warning , TEXT( "%s" ) , *MyName );

	// 조건문
	if( Number < 10 )
	{
	}
	else if( Number < 20 )
	{
	}
	else
	{
	}

	switch( Number/*조건이긴 하지만 정확히는 정수형 값*/ )
	{
		case 1:
		case 2:
			break;

		case 5:
			break;

		default:
			break;
	}

	// 반복문

	// 배열
	TArray<int32> ar;
	ar.Empty( 10 );
	ar.Add( 10 );
	ar.Add( 11 );
	ar.Add( 12 );
	if( false == ar.Contains( 5 ) )	// 5를 이미 포함하고 있지 않다면
	{
		ar.Add( 5 );	// 5를 추가하고 싶다.
	}

	ar.Num();	// Add한 갯수가 몇개인가?
	ar.GetSlack();	// 메모리공간을 몇개 할당 받았는가?

	for( int32 i = 0; i < ar.Num(); i++ )
	{
		UE_LOG( LogTemp , Warning , TEXT( " %d " ) , ar[i] );
	}

	// for each		
	for( int32 item : ar )
	{
		UE_LOG( LogTemp , Warning , TEXT( " %d " ) , item );
	}


	TMap<FString , int32> map;

	map.Add( "Coin" , 10 );
	if( false == map.Contains( "Coin" ) )
	{
		map.Add( "Coin" , 20 );
	}
	else
	{
		map["Coin"] = 20;
	}

	UE_LOG( LogTemp , Warning , TEXT( "%d" ) , map["Coin"] );


	for( TPair<FString , int32> pair : map )
	{
		UE_LOG( LogTemp , Warning , TEXT( "%s - %d" ) , *( pair.Key ) , pair.Value );
	}
	
}

// Called every frame
void ACodingPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACodingPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

