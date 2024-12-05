// Fill out your copyright notice in the Description page of Project Settings.

#include "Net/UnrealNetwork.h"
#include "HSGameModeBase.h"

AHSGameModeBase::AHSGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AHSGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ServerTick = 1.0f / DeltaTime;
}

void AHSGameModeBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AHSGameModeBase, ServerTick);
}
