// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/MonsterManager.h"

#include "SoundManager.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameObjects/MonsterAIController.h"
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

void AMonsterManager::ChangeStage(int soundVolume)
{
	//if 
}

void AMonsterManager::CheckRoaming()
{
	
	if (CurrentStage == EEnemyStage::Roaming)
	{
		//Spawn Character - after spawned blackboard should start actions
		if (!ActiveMonsterPawn)
		{
			//delay a few seconds and play audio of spawning
			
			ActiveMonsterPawn = GetWorld()->SpawnActor<AMonsterCharacter>(MonsterToSpawn, SpawnLocations[CurrentSection], FRotator::ZeroRotator);
			UE_LOG(LogTemp, Log, TEXT("Spawned Monster"));
			
			//get ai controller to have access to blackboard
			AIController = Cast<AMonsterAIController>(ActiveMonsterPawn->GetController());
			if (AIController)
			{
				//set blackboard sound location from value gained from delegate;
				AIController->GetBlackboardComponent()->SetValueAsVector("SoundPosition", SoundPosition);
				//set bool to start behavior tree process
				AIController->GetBlackboardComponent()->SetValueAsBool("CanStart", true);
			}
			else
			{
				UE_LOG(LogTemp, Log, TEXT("Cannot Find AIController"));
			}
		}
	}
}

void AMonsterManager::OnSoundRecieved(int32 soundVolume)
{
	//change tier based on soundVolume
	switch (CurrentStage)
	{
	case EEnemyStage::OutofWing: 
		if (soundVolume == 2){CurrentStage = EEnemyStage::InWing;}
		else if (soundVolume == 3){CurrentStage = EEnemyStage::Roaming;}
		CheckRoaming();
		break;
	case EEnemyStage::InWing:
		if (soundVolume == 1){CurrentStage = EEnemyStage::InSection;} 
		else if (soundVolume == 3 || soundVolume == 2){CurrentStage = EEnemyStage::Roaming;}
		CheckRoaming();
		break;
	case EEnemyStage::InSection:
		if (soundVolume == 1 || soundVolume == 2 || soundVolume == 3){CurrentStage = EEnemyStage::Roaming;}
		CheckRoaming();
		break;
	case EEnemyStage::Roaming:
		//set blackboard sound location - will make enemy pathfind to new position if not in chase
		AIController->GetBlackboardComponent()->SetValueAsVector("SoundPosition", SoundPosition);
		break;
	case EEnemyStage::None:
		break;
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Recieved Sound, Volume: %d"), soundVolume));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Current Stage: %d"), CurrentStage));
}

void AMonsterManager::OnSoundRecievedLocation(FVector soundLocation)
{
	SoundPosition = soundLocation;
}

void AMonsterManager::InitializeHearing()
{
	if (SoundManager)
	{
		SoundManager->OnSoundEmittedLocation.AddDynamic(this, &AMonsterManager::OnSoundRecievedLocation);
		SoundManager->OnSoundEmitted.AddDynamic(this, &AMonsterManager::OnSoundRecieved);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SoundManager reference not found in monster manager"));
	}
}

// Called every frame
void AMonsterManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

