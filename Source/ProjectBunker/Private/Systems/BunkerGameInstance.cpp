// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/BunkerGameInstance.h"

#include "InventoryManager.h"
#include "MonsterManager.h"
#include "SoundManager.h"

void UBunkerGameInstance::OnStart()
{
    Super::OnStart();
    CreateSoundManager();
    CreateMonsterManager();
    ActiveMonsterManager->SoundManager = ActiveSoundManager;
	ActiveMonsterManager->InitializeHearing();
    CreateInventoryManager();
}

void UBunkerGameInstance::Init()
{
	Super::Init();

	
	/*if (GetWorld())
	{
		{UE_LOG(LogTemp, Warning, TEXT("Started spawning"));}
		CreateSoundManager();
		CreateMonsterManager();
		ActiveMonsterManager->SoundManager = ActiveSoundManager;
		CreateInventoryManager();
	}
	else{UE_LOG(LogTemp, Warning, TEXT("did not spawn"));}*/
}

void UBunkerGameInstance::CreateMonsterManager()
{
	ActiveMonsterManager = GetWorld()->SpawnActor<AMonsterManager>(MonsterManagerToSpawn,
		FVector(0.f,0.f,0.f), FRotator::ZeroRotator);

	if (IsValid(ActiveMonsterManager))
	{
		UE_LOG(LogTemp, Warning, TEXT("created monster manager"));
	}
	else{UE_LOG(LogTemp, Warning, TEXT("monster manager failed"));}
}

void UBunkerGameInstance::CreateSoundManager()
{
	ActiveSoundManager = GetWorld()->SpawnActor<ASoundManager>(SoundManagerToSpawn,
		FVector(0.f,0.f,0.f), FRotator::ZeroRotator);
}

void UBunkerGameInstance::CreateInventoryManager()
{
	ActiveInventoryManager = GetWorld()->SpawnActor<AInventoryManager>(InventoryManagerToSpawn,
		FVector(0.f,0.f,0.f), FRotator::ZeroRotator);
}