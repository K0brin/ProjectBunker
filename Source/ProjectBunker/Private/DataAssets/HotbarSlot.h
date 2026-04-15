// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "HotbarSlot.generated.h"

/**
 * 
 */

class ASkeletalMeshActor;

UENUM()
enum class EObjectType : uint8
{
	Handgun,
	Flashlight,
	Bottle,
	Grenade,
	Healing,
	BoltCutters
};

UCLASS()
class UHotbarSlot : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) ASkeletalMeshActor* HeldGameObject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) EObjectType ObjectType;
	//sprite definition
	
};
