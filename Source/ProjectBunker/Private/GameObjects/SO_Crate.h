// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObjects/SoundObject.h"
#include "SO_Crate.generated.h"

/**
 * 
 */
UCLASS()
class ASO_Crate : public ASoundObject
{
	GENERATED_BODY()

public:
	virtual void MakeSound() override;
};
