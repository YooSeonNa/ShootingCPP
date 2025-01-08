// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CodingPawn.generated.h"

UCLASS()
class SHOOTINGCPP_API ACodingPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACodingPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// 자료형과 변수
	// 정수형, 실수형, 논리형, 문자열
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MyVar)
	int32 Number = 11;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MyVar)
	float Distance = 3.14f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MyVar)
	bool bGood = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=MyVar)
	FString MyName = TEXT("나유선");
};
