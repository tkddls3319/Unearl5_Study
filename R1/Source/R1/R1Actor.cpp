// Fill out your copyright notice in the Description page of Project Settings.


#include "R1Actor.h"
#include "R1LogChannels.h"
#include "R1Object.h"

// Sets default values
AR1Actor::AR1Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//한국어
}

// Called when the game starts or when spawned
void AR1Actor::BeginPlay()
{
	Super::BeginPlay();
	
	Obj1 = NewObject<UR1Object>();
}

// Called every frame
void AR1Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Obj1 == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("obj1 delete"));
	}
}

