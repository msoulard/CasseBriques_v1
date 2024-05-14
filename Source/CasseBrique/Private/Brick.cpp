// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"
#include "Components/BoxComponent.h"
#include "./Ball.h"

#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Create BoxComponent and set as RootComponent for the Actor
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;

	// Create StaticMeshComponent and Attach to BoxComponent
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(BoxCollision);



}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	this->OnActorEndOverlap.AddDynamic(this, &ABrick::OnOverlap);

	
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABrick::OnOverlap(AActor* MyActor, AActor* OtherActor)
{

	if (auto Brick = Cast<ABall>(OtherActor)) {
		if (Particle != NULL){
			// Transform --> Location, Rotation, Scale
			FTransform ParticleT;
			// Spawn Location
			ParticleT.SetLocation(this->GetActorLocation());
			// World Size Particule
			ParticleT.SetScale3D(FVector(3, 3, 3));
			// Spawn Particule
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particle, ParticleT, true);
		}
		if (MySound) {
			UGameplayStatics::PlaySound2D(GetWorld(), MySound);
		}
		this->Destroy();		
	}
}

