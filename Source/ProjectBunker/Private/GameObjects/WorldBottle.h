// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldBottle.generated.h"

class ASoundManager;

UCLASS()
class AWorldBottle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldBottle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//make sound when bumped into
	UPROPERTY(BlueprintReadWrite, EditAnywhere) ASoundManager* SoundManager;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UStaticMeshComponent* MeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)UStaticMesh* MeshAsset;
	
	UFUNCTION()void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, FVector NormalImpulse,const FHitResult& Hit);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
