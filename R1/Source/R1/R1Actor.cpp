// Fill out your copyright notice in the Description page of Project Settings.

#include "R1Actor.h"
#include "R1LogChannels.h"
#include "R1Object.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AR1Actor::AR1Actor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*Box = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Game/_Park/SM_Cylinder.SM_Cylinder'"));

	if (FindMesh.Succeeded())
	{
		Box->SetStaticMesh(FindMesh.Object);
	}*/

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	RootComponent = Body;
	Body->SetRelativeScale3D(FVector(1, 1, 1));

	Wing = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wing"));
	Wing->SetupAttachment(Body);
	Wing->SetRelativeLocationAndRotation(FVector(1, 1, 1), FRotator());

	Head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	Head->SetupAttachment(Body);
	Head->SetRelativeLocationAndRotation(FVector(1, 1, 1));

	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Game/_Park/SM_Cylinder.SM_Cylinder'"));

	if (FindMesh.Succeeded())
	{
		Body->SetStaticMesh(FindMesh.Object);
		Wing->SetStaticMesh(FindMesh.Object);
		Head->SetStaticMesh(FindMesh.Object);
	}
}

// Called when the game starts or when spawned
void AR1Actor::BeginPlay()
{
	Super::BeginPlay();

	Target = UGameplayStatics::GetActorOfClass(GetWorld(), AR1Actor::StaticClass());

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Psi"), Actors);

	if (Actors.Num() > 0)//몇개인지 확인할 때는 Empty()가 아닌 Num()사용
	{
		Target = Actors[0];
	}
}

// Called every frame
void AR1Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Target != nullptr)
	{
		float Speed = 50.0f;
		float Distance = DeltaTime * Speed;

		FVector Location = GetActorLocation();//현재위치

		//1.
		//FVector NewLocation = Location + FVector::ForwardVector * Distance;
		//SetActorLocation(NewLocation);//움직임

		//2.방향만알려주면 알아서 작동
		FVector DirectionVector = Target->GetActorLocation() - GetActorLocation();
		DirectionVector.Normalize();
		AddActorWorldOffset(DirectionVector * Distance);
	}
}

