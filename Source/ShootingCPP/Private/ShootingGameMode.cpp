// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingGameMode.h"
#include "MainWidget.h"
#include "Components/TextBlock.h"
#include "ShootingSaveGame.h"
#include "Kismet/GameplayStatics.h"

void AShootingGameMode::BeginPlay()
{
	Super::BeginPlay();

	// 저장되어 있는 데이터를 불러오자
	LoadGameData();

	if( mainWidget != nullptr )
	{
		// mainWidget 블루프린트 파일을 메모리에 로드한다.
		mainUI = CreateWidget<UMainWidget>( GetWorld(), mainWidget );

		// 위젯이 메모리에 로드되면 뷰 포트에 출력한다.
		if( mainUI != nullptr )
		{
			mainUI->AddToViewport();

			// 최고 점수 UI를 갱신해주자
			mainUI->SetHighScore( highScore );
		}
	}

}

// 현재 점수를 계산하는 함수
void AShootingGameMode::AddScore( int32 point )
{
	// 매개변수 point를 통해 넘겨받은 점수를 현재 점수에 누적한다.
	currentScore += point;
	//currentScore = currentScore + point;

	// 현재 점수를 위젯에 반영한다.
	PrintScore();

	// 현재 점수가 최고 점수를 넘어가면
	if( currentScore > highScore )
	{
		// 최고 점수를 현재 점수로 설정한다.
		highScore = currentScore;

		// 최고 점수를 저장해 놓자
		SaveGameData();

		// 최고점수 UI를 갱신해준다.
		PrintHighScore();
	}
}


void AShootingGameMode::SetHP( float Cur , float Max )
{
	if( mainUI == nullptr )	return;
	mainUI->SetHP( Cur, Max );
}

void AShootingGameMode::ShowGameOver( bool bShow )
{
	if( mainUI == nullptr )	return;
	mainUI->ShowGameOver( bShow );
}

void AShootingGameMode::PrintScore()
{
	if( mainUI != nullptr )
	{
		// scoreData 텍스트 블록에 현재 점수 값을 입력한다.
		//mainUI->scoreData->SetText( FText::AsNumber( currentScore ) );
		mainUI->SetScore( currentScore );
	}
}

void AShootingGameMode::PrintHighScore()
{
	if( mainUI == nullptr )	return;
	mainUI->SetHighScore( highScore );
}

void AShootingGameMode::SaveGameData()
{
	// ShooingSaveGame 객체를 만들고
	UShootingSaveGame* sg = Cast<UShootingSaveGame> ( UGameplayStatics::CreateSaveGameObject( UShootingSaveGame::StaticClass() ) );

	// 객체에 HighScoreSave 값을 HighScore로 갱신한다.
	sg->HighScoreSave = highScore;

	// 파일로 저장을 한다.
	UGameplayStatics::SaveGameToSlot( sg, SaveSlotName, UserIndex );
}

void AShootingGameMode::LoadGameData()
{
	// 파일이 존재하는지 확인하자
	bool isExist = UGameplayStatics::DoesSaveGameExist( SaveSlotName, UserIndex );
	if( isExist == false )	return;

	// 파일이 있으면 읽어서 ShootingSaveGame 객체를 생성하고
	UShootingSaveGame* sg = Cast<UShootingSaveGame>( UGameplayStatics::LoadGameFromSlot( SaveSlotName, UserIndex ) );
	if( sg == nullptr )	return;

	// highScore의 값을 파일에서 읽어온 값으로 갱신한다.
	highScore = sg->HighScoreSave;
}
