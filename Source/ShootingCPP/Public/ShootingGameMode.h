// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShootingGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGCPP_API AShootingGameMode : public AGameModeBase
{
	GENERATED_BODY()
	

public:
	void AddScore( int32 point );
	void SetHP( float Cur, float Max );

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UMainWidget> mainWidget;

	void ShowGameOver( bool bShow );

	// 저장하기 / 불러오기
	// HighScore 갱신될때 저장하고 싶다.
	// 게임이 시작될때 HighScore 값을 불러오고 싶다.
	// SlotName, UserIndex
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SaveSlotName = TEXT("HighScore");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 UserIndex = 0;

	void SaveGameData();
	void LoadGameData();







protected:
	virtual void BeginPlay() override;


private:
	// 현재 점수 저장용 변수
	int32 currentScore = 0;

	// 최고 점수 저장용 변수
	int32 highScore = 0;

	// 현재 뷰 포트에 로드된 위젯 저장용 변수
	class UMainWidget* mainUI;

	void PrintScore();
	void PrintHighScore();


	UPROPERTY(EditAnywhere)
	class USoundBase*	BGM;

};
