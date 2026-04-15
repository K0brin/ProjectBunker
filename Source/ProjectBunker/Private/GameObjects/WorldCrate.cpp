// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObjects/WorldCrate.h"

// Sets default values
AWorldCrate::AWorldCrate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWorldCrate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorldCrate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

