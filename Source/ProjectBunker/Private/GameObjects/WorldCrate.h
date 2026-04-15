// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldCrate.generated.h"

UCLASS()
class AWorldCrate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldCrate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//have push functionality and make sound on interval as pushing

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
