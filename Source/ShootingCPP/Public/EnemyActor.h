// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyActor.generated.h"

UCLASS()
class SHOOTINGCPP_API AEnemyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 충돌체, 외형, Speed
	// 1. 태어나서 앞으로 이동하고 싶다.
	// 2. 30% 확률적으로 플레이어를 향해서 이동하고 싶다.
	// 2-1. 아니면 앞으로 이동하고 싶다.
	UPROPERTY(EditAnywhere)
	class UBoxComponent* BoxComp;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComp;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RandomRate = 30;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Direction;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 600.0f;


};
