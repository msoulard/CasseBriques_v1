// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "./Brick.h"
#include "./Wall.h"
#include "./Paddle.h"
#include "./Wall_under.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;


	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	BallMesh->SetupAttachment(BoxCollision);

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();

	FVector initialveloce = FVector(1500, 1500 , 0);
	
	
	


	BallMesh->SetPhysicsLinearVelocity(initialveloce);
	//BallMesh->Enabled


	this->OnActorBeginOverlap.AddDynamic(this, &ABall::OnOverlap);
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector newveloce = BallMesh->GetPhysicsLinearVelocity();

	if(newveloce.X>=1500)
	{
		newveloce.X = 1500;
	}else if (newveloce.X <= -1500)
	{
		newveloce.X = -1500;
	}

	if (newveloce.Y >= 1500)
	{
		newveloce.Y = 1500;
	}
	else if (newveloce.Y <= -1500)
	{
		newveloce.Y = -1500;
	}


	if ((newveloce.Y * newveloce.Y + newveloce.X * newveloce.X) <= 1125000)
	{
		newveloce.X = newveloce.X * 1,2;
		newveloce.Y = newveloce.Y * 1,2;
	}



	BallMesh->SetPhysicsLinearVelocity(newveloce);


}

void ABall::OnOverlap(AActor* MyActor, AActor* OtherActor)
{

	if (auto Brick = Cast<ABrick>(OtherActor)) {

		FVector newveloce = BallMesh->GetPhysicsLinearVelocity();
		newveloce.X = newveloce.X * 3;
		newveloce.Y = newveloce.Y * 3;
		BallMesh->SetPhysicsLinearVelocity(newveloce);
	}

	if (auto Brick = Cast<AWall>(OtherActor)) {

		FVector newveloce = BallMesh->GetPhysicsLinearVelocity();
		newveloce.X = newveloce.X * 3;
		newveloce.Y = newveloce.Y * 3;
		BallMesh->SetPhysicsLinearVelocity(newveloce);
	}

	if (auto Brick = Cast<APaddle>(OtherActor)) {
		
		FVector newveloce = BallMesh->GetPhysicsLinearVelocity();
		newveloce.X = -newveloce.X ;
		newveloce.Y = newveloce.Y ;
		BallMesh->SetPhysicsLinearVelocity(newveloce);


	}
}

	

