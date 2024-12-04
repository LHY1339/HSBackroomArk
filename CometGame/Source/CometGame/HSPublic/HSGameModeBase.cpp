// Fill out your copyright notice in the Description page of Project Settings.

#include "Net/UnrealNetwork.h"
#include "HSGameModeBase.h"

void AHSGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ServerDeltaTime = DeltaTime;
}

void AHSGameModeBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AHSGameModeBase, ServerDeltaTime);
}
