// Fill out your copyright notice in the Description page of Project Settings.

#include "Net/UnrealNetwork.h"
#include "HSCharacter.h"

// Sets default values
AHSCharacter::AHSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AHSCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AHSCharacter, MaxCharacterHP);
	DOREPLIFETIME(AHSCharacter, MaxCharacterEnergy);
	DOREPLIFETIME(AHSCharacter, CharacterHP);
	DOREPLIFETIME(AHSCharacter, CharacterEnergy);
}

void AHSCharacter::OnPlayerLeavingGame_Implementation()
{
	Destroy();
}

