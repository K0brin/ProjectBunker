// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MonsterManager.generated.h"

class AMonsterAIController;
class ASoundManager;
class AMonsterCharacter;

UENUM()
enum class EEnemyStage : int8 { OutofWing, InWing, InSection, Roaming, None };

UCLASS()
class AMonsterManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMonsterManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) EEnemyStage CurrentStage = EEnemyStage::None;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AActor> MonsterToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AMonsterCharacter* ActiveMonsterPawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FVector> SpawnLocations;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 CurrentSection; //used as index for spawn location when spawning in roam
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector SoundPosition; //used as index for spawn location when spawning in roam
	UPROPERTY() AMonsterAIController* AIController = nullptr;
	
	UFUNCTION(BlueprintCallable) void ChangeStage(int soundVolume);
	UFUNCTION(BlueprintCallable) void CheckRoaming();
	
	//Sound Receiving
	UPROPERTY(EditAnywhere, BlueprintReadWrite) ASoundManager* SoundManager;
	UFUNCTION(BlueprintCallable) void OnSoundRecieved(int32 soundVolume);
	UFUNCTION(BlueprintCallable) void OnSoundRecievedLocation(FVector soundLocation);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
