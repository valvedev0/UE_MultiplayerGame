// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OverheadWidget.generated.h"

/**
 * 
 */
UCLASS()
class MENUSYSTEM_API UOverheadWidget : public UUserWidget
{
	GENERATED_BODY()

public:			
	
	//create a text block for displaying network role
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* DisplayText;

	// set the display text function 

	void SetDisplayText(FString TextToDisplay);

	//show the aplayer role
	UFUNCTION(BlueprintCallable)
	void ShowPlayerNetworkRole(APawn* InPawn);

protected:

	virtual void NativeDestruct() override;




	
};
