// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObjects/WorldObjectSpawner.h"
#include "DrawDebugHelpers.h"

// Sets default values
AWorldObjectSpawner::AWorldObjectSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWorldObjectSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorldObjectSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

