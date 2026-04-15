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

public: //house actions depending on equipped item using EObjectType
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<UHotbarSlot*> HotbarSlots;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
