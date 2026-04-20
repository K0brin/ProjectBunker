// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/InventoryManager.h"

#include "DataAssets/HotbarSlot.h"

// Sets default values
AInventoryManager::AInventoryManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInventoryManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void AInventoryManager::SetHeldItem(int32 index)
{
	//spawn the static mesh (heldgameobject)
	//set active item name
	HeldObjectType = HotbarSlots[index]->ObjectType;
}

void AInventoryManager::UseHeldItem()
{
	// call on left click when an item is being held
}

// Called every frame
void AInventoryManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

