// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HSPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class COMETGAME_API AHSPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void PawnLeavingGame() override;

	UFUNCTION(BlueprintCallable)
		void RayCreateTouchInterface();
};
