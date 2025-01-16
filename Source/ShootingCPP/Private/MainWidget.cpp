// Fill out your copyright notice in the Description page of Project Settings.


#include "MainWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "GameOverWidget.h"

void UMainWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetScore( 0 );
	SetHighScore( 0 );
	ShowGameOver( false );
}

void UMainWidget::SetScore( int32 NewScore )
{
	scoreData->SetText( FText::AsNumber( NewScore ) );
}

void UMainWidget::SetHighScore( int32 NewHighScore )
{
	scoreHighData->SetText( FText::AsNumber( NewHighScore ) );
}

void UMainWidget::SetHP( float Cur , float Max )
{	
	if( HPBar == nullptr )	return;
	HPBar->SetPercent( Cur / Max );
}

void UMainWidget::ShowGameOver( bool bShow )
{
	if( GameOverWidget == nullptr )	return;

	if( bShow )
	{
		GameOverWidget->SetVisibility( ESlateVisibility::Visible );
	}
	else
	{
		GameOverWidget->SetVisibility( ESlateVisibility::Hidden );
	}	

	//GameOverWidget->SetVisibility( bShow ? ESlateVisibility::Visible : ESlateVisibility::Hidden );
}
