#pragma once

#include "Interactable.generated.h"

UINTERFACE()
class PRACTICE3_API UInteractable : public UInterface
{
	GENERATED_BODY()
};

class PRACTICE3_API IInteractable
{
	GENERATED_BODY()
public:
	UFUNCTION( BlueprintNativeEvent, BlueprintCallable, Category = Interactable )
	bool CanInteract();
	virtual bool CanInteract_Implementation() { return true; }
	UFUNCTION( BlueprintNativeEvent, BlueprintCallable, Category = Interactable )
	void PerformInteract();
	virtual void PerformInteract_Implementation() {}
};
