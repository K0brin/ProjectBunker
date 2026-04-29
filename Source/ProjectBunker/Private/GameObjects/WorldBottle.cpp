// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObjects/WorldBottle.h"

#include "Systems/SoundManager.h"

// Sets default values
AWorldBottle::AWorldBottle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWorldBottle::BeginPlay()
{
	Super::BeginPlay();
	MeshComponent->OnComponentHit.AddDynamic(this, &AWorldBottle::OnHit);
}

void AWorldBottle::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor == GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		SoundManager->EmitSound(3, this->GetActorLocation());
	}
}

// Called every frame
void AWorldBottle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

