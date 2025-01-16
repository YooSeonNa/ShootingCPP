// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGCPP_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* Button_Restart;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* Button_Quit;

	UFUNCTION()
	void Restart();

	UFUNCTION()
	void Quit();
};
