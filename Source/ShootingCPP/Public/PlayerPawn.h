// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "PlayerPawn.generated.h"

//class UBoxComponent;
//class ABulletActor;

UCLASS()
class SHOOTINGCPP_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:
	// 충돌체 컴포넌트를 추가해서 Root컴포넌트로 설정
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* BoxComp;

	// 메시 컴포넌트를 추가해서 Root컴포넌트에 Attach
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* FirePositionComp;

	// 오른쪽으로 이동하고 싶다.
	// P = P0 + v(방향 * Speed)t

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 500.0f;


	// 사용자의 입력에 따라 상하좌우로 이동하고 싶다
	float h;
	float v;

	void OnAxisHorizontal( float value );
	void OnAxisVertical( float value );

	void OnActionFire();

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABulletActor> BulletFactory;

	UPROPERTY()
	class AShootingGameMode* GM;

	// 최대체력 / 현재체력
	float HP;

	UPROPERTY(EditAnywhere)
	float MaxHP = 2;

	// 데미지 처리
	void SetDamage( int32 damage );	// 적이 호출을 할 예정

};
