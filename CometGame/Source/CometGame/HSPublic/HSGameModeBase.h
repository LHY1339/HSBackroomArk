// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HSGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class COMETGAME_API AHSGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AHSGameModeBase();

	virtual void Tick(float DeltaTime) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UPROPERTY(Replicated)
		int32 ServerTick = 4;
};
