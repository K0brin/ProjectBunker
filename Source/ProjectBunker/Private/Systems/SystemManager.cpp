// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/SystemManager.h"

#include "InventoryManager.h"
#include "MonsterManager.h"
#include "SoundManager.h"

// Sets default values
ASystemManager::ASystemManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASystemManager::BeginPlay()
{
	Super::BeginPlay();

	CreateSoundManager();
	CreateMonsterManager();
	CreateInventoryManager();
}

// Called every frame
void ASystemManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASystemManager::CreateMonsterManager()
{
	ActiveMonsterManager = GetWorld()->SpawnActor<AMonsterManager>(MonsterManagerToSpawn,
		FVector(0.f,0.f,0.f), FRotator::ZeroRotator);
}

void ASystemManager::CreateSoundManager()
{
	ActiveSoundManager = GetWorld()->SpawnActor<ASoundManager>(SoundManagerToSpawn,
		FVector(0.f,0.f,0.f), FRotator::ZeroRotator);
}

void ASystemManager::CreateInventoryManager()
{
	ActiveInventoryManager = GetWorld()->SpawnActor<AInventoryManager>(InventoryManagerToSpawn,
		FVector(0.f,0.f,0.f), FRotator::ZeroRotator);
}
