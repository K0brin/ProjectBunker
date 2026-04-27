// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/HeldObjectType.h"
#include "GameFramework/Actor.h"
#include "InventoryManager.generated.h"


enum class EHeldObjectType : uint8;
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<UHotbarSlot*> HotbarInventory;
	UPROPERTY(BlueprintReadWrite) EHeldObjectType HeldObjectType = EHeldObjectType::None;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int HeldObjectIndex = -1;
	
	UFUNCTION(BlueprintCallable) void SetHeldItem(int32 index);
	UFUNCTION(BlueprintCallable) void UseHeldItem();
	UFUNCTION(BlueprintCallable) void FireGun();
	UFUNCTION(BlueprintCallable) void ThrowItem(bool isExplosive);
	UFUNCTION(BlueprintCallable) void Heal();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
