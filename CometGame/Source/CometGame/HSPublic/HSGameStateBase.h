// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "HSGameStateBase.generated.h"

class AHSGameModeBase;

UCLASS()
class COMETGAME_API AHSGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
};
