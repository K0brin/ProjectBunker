// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/SoundManager.h"

#include "MonsterManager.h"
#include "GameObjects/WorldBottle.h"
#include "GameObjects/WorldObjectSpawner.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASoundManager::ASoundManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASoundManager::BeginPlay()
{
	Super::BeginPlay();

	//find all spawners and add to array
	TArray<AActor*> spawnerActors;
	TArray<AWorldObjectSpawner*> worldObjectSpawners;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWorldObjectSpawner::StaticClass(),  spawnerActors);
	for (AActor* spawner : spawnerActors)
	{
		worldObjectSpawners.Add(Cast<AWorldObjectSpawner>(spawner));
	}

	//run function for spawning object type - require input array
	SpawnWorldObjects(worldObjectSpawners);
}

void ASoundManager::SpawnWorldObjects(TArray<AWorldObjectSpawner*> spawnerArray)
{

	for (AWorldObjectSpawner* spawner : spawnerArray)
	{
		//find which object it wants to spawn, find the position or designated spawn position and spawn it
	}
	
}


// Called every frame
void ASoundManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

