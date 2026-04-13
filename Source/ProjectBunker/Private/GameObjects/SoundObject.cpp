// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObjects/SoundObject.h"

#include "Kismet/GameplayStatics.h"
#include "Systems/SoundManager.h"

// Sets default values
ASoundObject::ASoundObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASoundObject::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASoundObject::MakeSound(int soundTier)
{
	ASoundManager* soundManager = Cast<ASoundManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ASoundManager::StaticClass()));
	soundManager->SendSound(soundTier);
}

// Called every frame
void ASoundObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

