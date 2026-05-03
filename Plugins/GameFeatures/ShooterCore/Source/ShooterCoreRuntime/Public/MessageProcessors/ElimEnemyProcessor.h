#pragma once

#include "CoreMinimal.h"
#include "Messages/GameplayMessageProcessor.h"
#include "ElimEnemyProcessor.generated.h"

struct FLyraVerbMessage;

UCLASS()
class UElimEnemyProcessor : public UGameplayMessageProcessor
{
	GENERATED_BODY()

public:
	virtual void StartListening() override;

protected:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag AccoladeElimEnemyTag;

private:
	void OnEnemyEliminationMessage(FGameplayTag Channel, const FLyraVerbMessage& Payload);
};