// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObjects/SoundObject.h"
#include "SO_Bottle.generated.h"

/**
 * 
 */
UCLASS()
class ASO_Bottle : public ASoundObject
{
	GENERATED_BODY()
public:
	ASO_Bottle();

protected:
	virtual void BeginPlay() override;
	
public:
	virtual void MakeSound(int soundTier) override;
};
