// Fill out your copyright notice in the Description page of Project Settings.

#include "HSCharacter.h"
#include "HSPlayerController.h"

void AHSPlayerController::PawnLeavingGame()
{
	if (GetPawn() == NULL)
	{
		return;
	}
	AHSCharacter* character = Cast<AHSCharacter>(GetPawn());
	if (character)
	{
		character->OnPlayerLeavingGame();
	}
	else
	{
		GetPawn()->Destroy();
		SetPawn(NULL);
	}
}

void AHSPlayerController::RayCreateTouchInterface()
{
	Super::CreateTouchInterface();
}
