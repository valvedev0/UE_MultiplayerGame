// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "LobbyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MENUSYSTEM_API ALobbyGameMode : public AGameModeBase
{
	GENERATED_BODY()
	

public:

	// create 2 fns that take ref from APLyerController

	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void Logout(APlayerController* Exiting)  ;
};
