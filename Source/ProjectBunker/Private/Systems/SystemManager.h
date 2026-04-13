// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SystemManager.generated.h"

class ASoundManager;
class AMonsterManager;
class AInventoryManager;

UCLASS()
class ASystemManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASystemManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};