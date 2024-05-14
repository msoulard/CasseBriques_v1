// Fill out your copyright notice in the Description page of Project Settings.


#include "Particle.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AParticle::AParticle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AParticle::BeginPlay()
{
	Super::BeginPlay();
    if (Particle != NULL)
    {
        // Transform --> Location, Rotation, Scale
        FTransform ParticleT;
        // Spawn Location
        ParticleT.SetLocation(this->GetActorLocation());
        // World Size Particule
        ParticleT.SetScale3D(FVector(3, 3, 3));
        // Spawn Particule
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particle, ParticleT, true);
    }
}

// Called every frame
void AParticle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

