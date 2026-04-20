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
	Flashlight,
	Bottle,
	Grenade,
	Healing,
	BoltCutters
};

class HeldObjectType
{
public:
	HeldObjectType();
	~HeldObjectType();
};
