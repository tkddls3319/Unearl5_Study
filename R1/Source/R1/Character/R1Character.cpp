


#include "Character/R1Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "R1Define.h"

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

void AR1Character::HandleGamplayEvent(FGameplayTag EventTag)
{
}

void AR1Character::Highlight()
{
	bHighlighted = true;
	GetMesh()->SetRenderCustomDepth(true);//postprocess 적용
	GetMesh()->SetCustomDepthStencilValue(250);//postprocess 적용
}

void AR1Character::UnHighlight()
{
	bHighlighted = false;
}

void AR1Character::OnDamaged(int32 Damage, TObjectPtr<AR1Character> Attacket)
{
	Hp = FMath::Clamp(Hp - Damage, 0, MaxHp);
	if (Hp == 0)
	{
		OnDead(Attacket);
	}

	D(FString::Printf(TEXT("%d"), Hp));
}

void AR1Character::OnDead(TObjectPtr<AR1Character> Attacket)
{
	if (CreatureState == ECreatureState::Dead)
		return;

	CreatureState = ECreatureState::Dead;
}

