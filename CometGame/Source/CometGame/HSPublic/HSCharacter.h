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
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Replicated, Category = "CharacterProperty")
		int32 MaxCharacterHP = 100;

	UPROPERTY(BlueprintReadWrite, Replicated, Category = "CharacterProperty")
		int32 CharacterHP = MaxCharacterHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "CharacterProperty")
		int32 MaxCharacterArmor = 100;

	UPROPERTY(BlueprintReadWrite, Replicated, Category = "CharacterProperty")
		int32 CharacterArmor = MaxCharacterArmor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "CharacterProperty")
		int32 MaxCharacterArmor = 100;

	UPROPERTY(BlueprintReadWrite, Replicated, Category = "CharacterProperty")
		int32 CharacterArmor = MaxCharacterArmor;
};
