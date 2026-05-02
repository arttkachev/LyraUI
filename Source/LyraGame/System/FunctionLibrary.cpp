// Fill out your copyright notice in the Description page of Project Settings.


#include "System/FunctionLibrary.h"

float UFunctionLibrary::GetEditorTime()
{
  return FApp::GetCurrentTime() - GStartTime;
}
