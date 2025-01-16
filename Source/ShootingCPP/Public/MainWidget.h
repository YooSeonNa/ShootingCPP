// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGCPP_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* scoreText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* scoreData;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* scoreHighText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* scoreHighData;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* HPBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UGameOverWidget* GameOverWidget;



	
	void SetScore( int32 NewScore );
	void SetHighScore( int32 NewHighScore );

	void SetHP( float Cur, float Max );

	void ShowGameOver( bool bShow );
	
};
