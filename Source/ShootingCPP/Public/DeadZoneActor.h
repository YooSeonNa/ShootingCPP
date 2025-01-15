// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeadZoneActor.generated.h"

UCLASS()
class SHOOTINGCPP_API ADeadZoneActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeadZoneActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap( AActor* OtherActor ) override;


public:
	UPROPERTY(EditAnywhere)
	class UBoxComponent* BoxComp;
	
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComp;


	UFUNCTION()
	void OnDeadZoneOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
						    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
						    bool bFromSweep, const FHitResult& SweepResult );
};
