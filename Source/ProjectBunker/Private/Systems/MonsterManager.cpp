// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/MonsterManager.h"

#include "GameObjects/MonsterCharacter.h"

// Sets default values
AMonsterManager::AMonsterManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMonsterManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMonsterManager::AdvanceStage(int soundTier)
{
}

void AMonsterManager::DecrementStage(int decrementValue)
{
}

void AMonsterManager::StartRoaming(int spawnIndex)
{
	//Spawn Character - after spawned blackboard should start actions
	ActiveMonsterPawn = GetWorld()->SpawnActor<AMonsterCharacter>(MonsterToSpawn, SpawnLocations[spawnIndex], FRotator::ZeroRotator);
}

// Called every frame
void AMonsterManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

