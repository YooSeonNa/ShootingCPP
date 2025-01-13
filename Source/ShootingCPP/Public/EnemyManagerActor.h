// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyManagerActor.generated.h"

// 일정시간마다 Enemy를 생성하고 배치하고 싶다.
// - 현재시간, 생성시간, EnemyFactory

UCLASS()
class SHOOTINGCPP_API AEnemyManagerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyManagerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay( const EEndPlayReason::Type EEndPlayReason ) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	// 일정시간마다 Enemy를 생성하고 배치하고 싶다.
	// - 현재시간, 생성시간, EnemyFactory( UClass:TSubclassOf )
	UPROPERTY(EditAnywhere, BlueprintReadOnly);
	float CurrentTime = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	float MakeTime = 1.0f;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AEnemyActor> EnemyFactory;

	UPROPERTY(EditAnywhere)
	class USceneComponent* RootComp;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* Origin;


	void MakeEnemy();
	

	FTimerHandle Handle;
};
