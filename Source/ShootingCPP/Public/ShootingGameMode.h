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

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UMainWidget> mainWidget;

protected:
	virtual void BeginPlay() override;


private:
	// 현재 점수 저장용 변수
	int32 currentScore = 0;

	// 현재 뷰 포트에 로드된 위젯 저장용 변수
	class UMainWidget* mainUI;

	void PrintScore();
};
