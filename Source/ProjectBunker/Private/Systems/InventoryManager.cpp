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
	//set cooresponding mesh to visible on player pawn, set all others to not visible (done in blueprint)
	
	//set active item name
	HeldObjectIndex = index;
	HeldObjectType = HotbarInventory[index]->ObjectType;
	
}

void AInventoryManager::UseHeldItem()
{
	// call on left click when an item is being held - call in blueprint

	if (HeldObjectIndex != -1 && HotbarInventory[HeldObjectIndex]->CurrentStack >= 1 )
	{
		switch (HeldObjectType)
		{
		case EHeldObjectType::Handgun: FireGun(); //Fire Gun
		case EHeldObjectType::Bottle: ThrowItem(false); //Throw Bottle
		case EHeldObjectType::Grenade: ThrowItem(true); //Throw Grenade
		case EHeldObjectType::Healing: Heal(); //Use Heals
		case EHeldObjectType::BoltCutters: break; //Use BoltCutters
		case EHeldObjectType::None: break; //Holding Nothing
		}
	}
}

void AInventoryManager::FireGun()
{
	//basic gun logic
}

void AInventoryManager::ThrowItem(bool isExplosive)
{
	//spawn throwable actor -> apply force to object -> when object hits surface -> make sound and explode (based on isExplosive)
}

void AInventoryManager::Heal()
{
	//heal designated health amount
}

// Called every frame
void AInventoryManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

