// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MonsterManager.generated.h"

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

	UFUNCTION(BlueprintCallable) void AdvanceStage(int soundTier);
	UFUNCTION(BlueprintCallable) void DecrementStage(int decrementValue);
	UFUNCTION(BlueprintCallable) void StartRoaming(int spawnIndex);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
