// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "HotbarSlot.generated.h"

/**
 * 
 */

enum class EHeldObjectType : uint8;
class ASkeletalMeshActor;

UCLASS(BlueprintType)
class UHotbarSlot : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UStaticMesh* HeldGameObject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) EHeldObjectType ObjectType;
	//sprite definition
	
};
