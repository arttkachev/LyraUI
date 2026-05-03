// Fill out your copyright notice in the Description page of Project Settings.

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
