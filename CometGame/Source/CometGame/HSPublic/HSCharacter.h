// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HSCharacter.generated.h"

UCLASS()
class COMETGAME_API AHSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UFUNCTION(BlueprintNativeEvent)
		void OnPlayerLeavingGame();
	virtual void OnPlayerLeavingGame_Implementation();

public:
	UPROPERTY(Replicated)
		FVector RepLocation;

	UPROPERTY(Replicated)
		FRotator RepRotation;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Replication")
		bool NewRepMovement = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Replicated, Category = "Replication")
		int32 NewRepMovementTickRate = 8;

public:
	UFUNCTION(BlueprintCallable)
		void SetMaxWalkSpeed(float speed);

private:

	UFUNCTION(Server, Reliable)
		void __SetMaxWalkSpeed_Server(float speed);
	virtual void __SetMaxWalkSpeed_Server_Implementation(float speed);

	UFUNCTION(Server, UnReliable)
		void __UpdateRepTransform_Server(FVector _location_, FRotator _rotation_);
	virtual void __UpdateRepTransform_Server_Implementation(FVector _location_, FRotator _rotation_);

	void __SmoothTransform();

	void __GetServerTickRate();

};
