// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "ShootingSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGCPP_API UShootingSaveGame : public ULocalPlayerSaveGame
{
	GENERATED_BODY()


public:
	// 저장하고 싶은 값을 담을 변수를 만든다.
	UPROPERTY(BlueprintReadWrite)
	int32 HighScoreSave;	
};
