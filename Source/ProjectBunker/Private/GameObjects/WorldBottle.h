// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldBottle.generated.h"

UCLASS()
class AWorldBottle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldBottle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//make sound when bumped into
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
