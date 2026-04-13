// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundObject.generated.h"

UCLASS()
class ASoundObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASoundObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void MakeSound();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
