


#include "MainActor.h"
#include "R1Actor.h"
AMainActor::AMainActor()
{
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FClassFinder<AR1Actor> FindClass(TEXT("/Script/Engine.Blueprint'/Game/_Park/BP_R1Actor.BP_R1Actor_C'"));
	if (FindClass.Succeeded())
	{
		ActorClass = FindClass.Class;
	}
}

void AMainActor::BeginPlay()
{
	Super::BeginPlay();

	FVector Location(0, 0, 0);
	FRotator Rotation(0, 0, 0);

	//1.
	AR1Actor* BeginActor = GetWorld()->SpawnActor<AR1Actor>(Location, Rotation);
	GetWorld()->DestroyActor(BeginActor);//제거

	//2.
	//CAST는 DYNAMIC CAST와 같이 상속구조확인을 해 준다. C# is, as와 같음
	Actor = Cast<AR1Actor>(GetWorld()->SpawnActor(ActorClass));//spawning
	Actor->SetLifeSpan(5.0f);//제거

	
}

// Called every frame
void AMainActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

