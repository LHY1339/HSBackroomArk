// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "HSGameStateBase.generated.h"

UCLASS()
class COMETGAME_API AHSGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	AHSGameStateBase();

	virtual void Tick(float DeltaTime) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(Replicated)
		int32 ServerTick = 4;
};
