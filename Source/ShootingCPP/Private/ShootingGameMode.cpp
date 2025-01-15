// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingGameMode.h"
#include "MainWidget.h"
#include "Components/TextBlock.h"

void AShootingGameMode::BeginPlay()
{
	Super::BeginPlay();

	if( mainWidget != nullptr )
	{
		// mainWidget 블루프린트 파일을 메모리에 로드한다.
		mainUI = CreateWidget<UMainWidget>( GetWorld(), mainWidget );

		// 위젯이 메모리에 로드되면 뷰 포트에 출력한다.
		if( mainUI != nullptr )
		{
			mainUI->AddToViewport();
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
}

void AShootingGameMode::PrintScore()
{
	if( mainUI != nullptr )
	{
		// scoreData 텍스트 블록에 현재 점수 값을 입력한다.
		mainUI->scoreData->SetText( FText::AsNumber( currentScore ) );
	}
}

