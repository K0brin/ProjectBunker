// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundManager.generated.h"

class AWorldBottle;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSoundEmitted, int32, soundVolume);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSoundEmittedLocation, FVector, soundLocation);

class AWorldObjectSpawner;

UCLASS()
class ASoundManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASoundManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable) void SpawnWorldObjects(TArray<AWorldObjectSpawner*> spawnerArray);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AWorldBottle> BottleToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AActor> CrateToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AActor> TripwireToSpawn;
	
	UPROPERTY(BlueprintAssignable) FOnSoundEmitted OnSoundEmitted;
	UPROPERTY(BlueprintAssignable) FOnSoundEmittedLocation OnSoundEmittedLocation;
	UFUNCTION(BlueprintCallable) void EmitSound(int32 soundVolume, FVector soundLocation)
	{
		UE_LOG(LogTemp, Log, TEXT("Emitting sound at volume: %d"), soundVolume);
		UE_LOG(LogTemp, Log, TEXT("Emitting sound at location: %s"), *soundLocation.ToString());
		OnSoundEmittedLocation.Broadcast(soundLocation);
		OnSoundEmitted.Broadcast(soundVolume);
	}
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
