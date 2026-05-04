#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LyraFunctionLibrary.generated.h"

UCLASS()
class ULyraFunctionLibrary : public UBlueprintFunctionLibrary
{
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintPure, Category = "Time")
  static inline double GetEditorTime() { return FApp::GetCurrentTime() - GStartTime; };
};