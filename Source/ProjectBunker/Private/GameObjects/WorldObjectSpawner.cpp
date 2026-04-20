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

	//function to check objectToSpawn type - show debug of outline of object in editor
	
}

void AWorldObjectSpawner::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	FColor BoxColor = FColor::White;
	if (SpawnType == ESpawnObjectType::Bottle)
	{
		
	}
	
	DrawDebugBox(GetWorld(), GetActorLocation(), FVector(20,20,20), FColor::Green, false, 0.1f, 0, 2.0f );
	
}

// Called every frame
void AWorldObjectSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

