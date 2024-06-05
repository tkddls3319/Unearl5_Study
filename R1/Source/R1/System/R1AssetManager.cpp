#include "System/R1AssetManager.h"
#include "R1LogChannels.h"

UR1AssetManager::UR1AssetManager() : Super()
{

}

UR1AssetManager& UR1AssetManager::Get()
{
	if (UR1AssetManager* Singleton = Cast<UR1AssetManager>(GEngine->AssetManager))
	{
		return *Singleton;
	}

	UE_LOG(LogR1, Fatal, TEXT("Can't find UR1AssetManager"));

	return *NewObject<UR1AssetManager>();
}
