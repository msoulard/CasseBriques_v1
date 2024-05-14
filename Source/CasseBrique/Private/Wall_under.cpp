// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall_under.h"
#include "Components/BoxComponent.h"

// Sets default values
AWall_under::AWall_under()
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
void AWall_under::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AWall_under::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
