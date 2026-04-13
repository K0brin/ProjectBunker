// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObjects/SO_Bottle.h"

// Sets default values
ASO_Bottle::ASO_Bottle()
{
}

void ASO_Bottle::BeginPlay()
{
	Super::BeginPlay();
}

//on player collision make a sound
void ASO_Bottle::MakeSound(int soundTier)
{
	Super::MakeSound(soundTier);
}
