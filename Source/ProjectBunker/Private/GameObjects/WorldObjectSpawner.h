// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldObjectSpawner.generated.h"

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

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AActor> objectToSpawn;
	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
