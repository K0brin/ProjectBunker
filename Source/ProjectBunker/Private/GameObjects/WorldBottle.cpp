// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObjects/WorldBottle.h"

#include "Systems/SoundManager.h"

// Sets default values
AWorldBottle::AWorldBottle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void AWorldBottle::BeginPlay()
{
	Super::BeginPlay();
	MeshComponent->SetStaticMesh(MeshAsset);
	MeshComponent->SetSimulatePhysics(true);
	MeshComponent->SetCollisionProfileName(TEXT("BlockAll"));
	MeshComponent->SetNotifyRigidBodyCollision(true);
	MeshComponent->CanCharacterStepUpOn = ECB_No;
	MeshComponent->SetMassOverrideInKg(NAME_None, 30.0f);
	MeshComponent->SetLinearDamping(5.0f);
	MeshComponent->SetAngularDamping(5.0f);
	MeshComponent->SetWorldScale3D(FVector(0.1f));
	MeshComponent->OnComponentHit.AddDynamic(this, &AWorldBottle::OnHit);
}

void AWorldBottle::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (GetWorldTimerManager().IsTimerActive(TimerHandle)) return;
	
	AActor* hitActor = OtherActor;
	
	GetWorldTimerManager().SetTimer(TimerHandle, [this, hitActor]()
	{
		if (hitActor == GetWorld()->GetFirstPlayerController()->GetPawn())
		{
			SoundManager->EmitSound(2, GetActorLocation());
		}
	}, 0.1f, false);
	
}

// Called every frame
void AWorldBottle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

