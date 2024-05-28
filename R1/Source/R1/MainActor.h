#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainActor.generated.h"

UCLASS()
class R1_API AMainActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMainActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	TObjectPtr<class AR1Actor> Actor;

	UPROPERTY()
	TSubclassOf<AR1Actor> ActorClass;//AR1Actor를 상속받은 모든걸 담을 수 있다.
};
