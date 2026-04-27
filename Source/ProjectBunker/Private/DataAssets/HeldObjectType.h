// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM()
enum class EHeldObjectType : uint8
{
	Handgun,
	Bottle,
	Grenade,
	Healing,
	BoltCutters,
	None
};

class HeldObjectType
{
public:
	HeldObjectType();
	~HeldObjectType();
};
