// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryManager.generated.h"

class UHotbarSlot;

UCLASS()
class AInventoryManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventoryManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	UPROPERTY(EditAnywhere) TArray<UHotbarSlot*> PlayerHotbar; //make data asset - holds model/blueprint and maybe other values
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
