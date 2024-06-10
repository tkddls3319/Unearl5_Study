


#include "Character/R1Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

AR1Character::AR1Character()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AR1Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AR1Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

