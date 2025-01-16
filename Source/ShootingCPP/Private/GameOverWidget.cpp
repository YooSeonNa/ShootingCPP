// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverWidget.h"
#include "Components/Button.h"

void UGameOverWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	// 각 버튼 입력 이벤트에 대응하는 함수를 연결해준다.
	Button_Restart->OnClicked.AddDynamic( this, &UGameOverWidget::Restart );
	Button_Quit->OnClicked.AddDynamic( this, &UGameOverWidget::Quit );
}

void UGameOverWidget::Restart()
{

}

void UGameOverWidget::Quit()
{

}
