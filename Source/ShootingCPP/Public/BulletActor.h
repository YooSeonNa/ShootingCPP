// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletActor.generated.h"

UCLASS()
class SHOOTINGCPP_API ABulletActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	// 태어나서 앞으로 계속 이동하고 싶다.
	// 외형, 충돌체, Speed
	// 
	// 충돌체 컴포넌트를 추가해서 Root컴포넌트로 설정
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* BoxComp;

	// 메시 컴포넌트를 추가해서 Root컴포넌트에 Attach
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* MeshComp;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 1000.0f;

};
