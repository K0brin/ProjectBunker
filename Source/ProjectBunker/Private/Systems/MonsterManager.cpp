// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/MonsterManager.h"

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

void AMonsterManager::RecieveSound(int soundTier)
{
	//depending on sound tier change monster stage
	switch (soundTier)
	{
	case 1: break;//Tier 1
	case 2: break;//Tier 2
	case 3: break;//Tier 3
	default: break;
	}
}

// Called every frame
void AMonsterManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

