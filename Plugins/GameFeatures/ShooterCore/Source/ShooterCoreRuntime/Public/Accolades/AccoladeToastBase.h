#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AccoladeToastBase.generated.h"

struct FPendingAccoladeEntry;

UCLASS()
class UAccoladeToastBase : public UUserWidget
{
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
  void PopulateAccoladeToastWidget(const FPendingAccoladeEntry& Data);
};