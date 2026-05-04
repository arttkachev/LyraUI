
#include "System/FunctionLibrary.h"

float UFunctionLibrary::GetEditorTime()
{
  return FApp::GetCurrentTime() - GStartTime;
}