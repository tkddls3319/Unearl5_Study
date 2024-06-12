

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "R1PlayerController.generated.h"

struct FInputActionValue;
class UNiagaraSystem;
/**
 * 
 */
UCLASS()
class R1_API AR1PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AR1PlayerController(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void OnInputStarted();
	void OnSetDestinationTriggered();
	void OnSetDestinationReleased();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold = 0.3f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr< UNiagaraSystem> FXCursor;

private:
	FVector CachedDestination;//목적지
	float FollowTime;
};
