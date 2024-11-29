// Fill out your copyright notice in the Description page of Project Settings.


#include "HSActor.h"

// Sets default values
AHSActor::AHSActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	SetReplicateMovement(true);
}

// Called when the game starts or when spawned
void AHSActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHSActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

