// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BunkerGameInstance.generated.h"

class AInventoryManager;
class ASoundManager;
class AMonsterManager;
/**
 * 
 */
UCLASS()
class UBunkerGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	
	
public:
	UFUNCTION(BlueprintCallable) void CreateMonsterManager();
	UFUNCTION(BlueprintCallable) void CreateSoundManager();
	UFUNCTION(BlueprintCallable) void CreateInventoryManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AActor> MonsterManagerToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AActor> SoundManagerToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AActor> InventoryManagerToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) AMonsterManager* ActiveMonsterManager;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) ASoundManager* ActiveSoundManager;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AInventoryManager* ActiveInventoryManager;
	
};
