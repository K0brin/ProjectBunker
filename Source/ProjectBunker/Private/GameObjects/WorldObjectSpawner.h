// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldObjectSpawner.generated.h"

class AWorldBottle;
class AWorldCrate;
class AWorldTripwire;

UENUM()
enum class ESpawnObjectType : uint8 { Bottle, Crate, Tripwire, None };

UCLASS()
class AWorldObjectSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldObjectSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) ESpawnObjectType SpawnType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AWorldBottle> BottleSpawn; //set in code depending on enum type
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AWorldCrate> CrateSpawn; //set in code depending on enum type
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AWorldTripwire> TripwireSpawn; //set in code depending on enum type
	//make spawn reference on spawn manager not held on each spawner - bad for performance - have spawn manager go through each and spawn
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
