// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
#include "HSGameStateBase.h"
#include "HSCharacter.h"

// Sets default values
AHSCharacter::AHSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetReplicateMovement(false);
	bReplicates = true;
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

	if (NewRepMovement)
	{
		if (IsLocallyControlled())
		{
			__UpdateRepTransform_Server(GetActorLocation(), GetActorRotation());
			__GetServerTickRate();
		}
		else
		{
			__SmoothTransform();
		}
	}
}

// Called to bind functionality to input
void AHSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AHSCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AHSCharacter, RepLocation);
	DOREPLIFETIME(AHSCharacter, RepRotation);
	DOREPLIFETIME(AHSCharacter, NewRepMovementTickRate);
}

void AHSCharacter::OnPlayerLeavingGame_Implementation()
{
	Destroy();
}

void AHSCharacter::SetMaxWalkSpeed(float speed)
{
	GetCharacterMovement()->MaxWalkSpeed = speed;
	__SetMaxWalkSpeed_Server(speed);
}

void AHSCharacter::__SetMaxWalkSpeed_Server_Implementation(float speed)
{
	GetCharacterMovement()->MaxWalkSpeed = speed;
}

void AHSCharacter::__UpdateRepTransform_Server_Implementation(FVector _location_, FRotator _rotation_)
{
	RepLocation = _location_;
	RepRotation = _rotation_;
}

void AHSCharacter::__SmoothTransform()
{
	FVector _newlocation_ = UKismetMathLibrary::VInterpTo_Constant(
		GetActorLocation(),
		RepLocation,
		UGameplayStatics::GetWorldDeltaSeconds(GetWorld()),
		UKismetMathLibrary::Vector_Distance(GetActorLocation(), RepLocation) * NewRepMovementTickRate
	);
	SetActorLocation(_newlocation_);

	float _rotatorspeed_ = UKismetMathLibrary::Abs(UKismetMathLibrary::NormalizedDeltaRotator(GetActorRotation(), RepRotation).Yaw * NewRepMovementTickRate);

	FRotator _newrotation_ = UKismetMathLibrary::RInterpTo_Constant(
		GetActorRotation(),
		RepRotation,
		UGameplayStatics::GetWorldDeltaSeconds(GetWorld()),
		_rotatorspeed_
	);

	SetActorRotation(_newrotation_);
}

void AHSCharacter::__GetServerTickRate()
{
	AHSGameStateBase* state = Cast<AHSGameStateBase>(UGameplayStatics::GetGameState(GetWorld()));
	if (state)
	{
		NewRepMovementTickRate = state->ServerTick;
	}
}

