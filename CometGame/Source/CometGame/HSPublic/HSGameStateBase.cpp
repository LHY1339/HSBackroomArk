// Fill out your copyright notice in the Description page of Project Settings.

#include "HSGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "HSGameModeBase.h"
#include "Net/UnrealNetwork.h"
#include "HSGameStateBase.h"

AHSGameStateBase::AHSGameStateBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AHSGameStateBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AHSGameModeBase* mode = Cast<AHSGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (mode)
	{
		ServerTick = mode->ServerTick;
	}
}

void AHSGameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AHSGameStateBase, ServerTick);
}

void AHSGameStateBase::BeginPlay()
{
	Super::BeginPlay();
}
