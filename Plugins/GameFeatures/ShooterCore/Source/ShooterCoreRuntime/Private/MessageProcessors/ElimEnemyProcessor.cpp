#include "MessageProcessors/ElimEnemyProcessor.h"

#include "GameFramework/PlayerState.h"
#include "Messages/LyraVerbMessage.h"
#include "NativeGameplayTags.h"
#include "Kismet/GameplayStatics.h"

namespace EnemyElim
{
  UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_Lyra_Elimination_Message, "Lyra.Elimination.Message");
}

void UElimEnemyProcessor::StartListening()
{
  UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(this);
  AddListenerHandle(MessageSubsystem.RegisterListener(EnemyElim::TAG_Lyra_Elimination_Message, this, &ThisClass::OnEnemyEliminationMessage));
}

void UElimEnemyProcessor::OnEnemyEliminationMessage(FGameplayTag Channel, const FLyraVerbMessage& Payload)
{
	if (!AccoladeElimEnemyTag.IsValid())
	{
		return;
	}
	const auto PC = GetWorld()->GetFirstPlayerController();
	if (!PC)
	{
		return;
	}
	const auto PS = PC->PlayerState;
	if (PC->PlayerState != Payload.Instigator)
	{
		return;
	} 
	UKismetSystemLibrary::PrintString(this, TEXT("Kill!!!!!"), true, true, FLinearColor::Red);
	FLyraVerbMessage ElimEnemeyMessage;
	ElimEnemeyMessage.Verb = AccoladeElimEnemyTag;
	ElimEnemeyMessage.Instigator = Payload.Instigator;
	ElimEnemeyMessage.InstigatorTags = Payload.InstigatorTags;
	ElimEnemeyMessage.ContextTags = Payload.ContextTags;
	ElimEnemeyMessage.Magnitude = 1.0;
	UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(this);
	MessageSubsystem.BroadcastMessage(ElimEnemeyMessage.Verb, ElimEnemeyMessage);
}
