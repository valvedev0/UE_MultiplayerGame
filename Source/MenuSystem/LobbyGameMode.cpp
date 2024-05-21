                // Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"
void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	 // display the no players and name of the player

	Super::PostLogin(NewPlayer);
	if (GameState)
	{
		int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				1,
				60.f,
				FColor::Yellow,
				FString::Printf(TEXT("Players in game: %d"), NumberOfPlayers)
		
			);
		

			// fetch the player name musing the player state

			APlayerState* PlayerState = NewPlayer->GetPlayerState<APlayerState>();
			if (PlayerState)
			{
				FString PlayerName = PlayerState->GetPlayerName();
				GEngine->AddOnScreenDebugMessage(
					-1,
					60.f,
					FColor::Cyan,
					FString::Printf(TEXT("%s has joined the game"), *PlayerName)
				);
			}
		}
		if (NumberOfPlayers == 2)
		{
			UWorld* World = GetWorld();
			if (World)
			{
				bUseSeamlessTravel = true;
				World->ServerTravel(FString("/Game/Maps/BlasterMap?listen"));
			}
		}
	}
}

void ALobbyGameMode::Logout(APlayerController* Exiting)
{

	Super::Logout(Exiting);

	APlayerState* PlayerState = Exiting->GetPlayerState<APlayerState>();
	if (PlayerState)
	{
		FString PlayerName = PlayerState->GetPlayerName();
		GEngine->AddOnScreenDebugMessage(
			-1,
			60.f,
			FColor::Cyan,
			FString::Printf(TEXT("%s has exited the game"), *PlayerName)
		);
	}

}
