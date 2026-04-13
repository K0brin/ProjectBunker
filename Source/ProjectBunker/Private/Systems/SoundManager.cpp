// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/SoundManager.h"

#include "MonsterManager.h"

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
	
}

void ASoundManager::SendSound(int soundTier)
{
	//send sound tier to monster manager (1-3)
	monsterManager->RecieveSound(soundTier);
}

// Called every frame
void ASoundManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

