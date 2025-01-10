// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TailActor.generated.h"

// 살아가면서 목적지를 향해 계속 이동하고싶다.
// - Target : 목적지
// - Speed

UCLASS()
class SHOOTINGCPP_API ATailActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATailActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	// Cube 외형을 만들고 싶다.
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComp;

	// Target
	UPROPERTY(EditAnywhere)
	class AActor* Target;

	// Speed
	UPROPERTY(EditAnywhere)
	float Speed = 450.0f;

};
