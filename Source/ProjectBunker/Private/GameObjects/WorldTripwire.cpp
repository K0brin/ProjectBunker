// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObjects/WorldTripwire.h"

// Sets default values
AWorldTripwire::AWorldTripwire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWorldTripwire::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorldTripwire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

