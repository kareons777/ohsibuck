#pragma once

#include "Openable.generated.h"

UINTERFACE()
class PRACTICE3_API UOpenable : public UInterface
{
	GENERATED_BODY()
};

class PRACTICE3_API IOpenable
{
	GENERATED_BODY()
public:
	UFUNCTION( BlueprintNativeEvent, BlueprintCallable, Category = Interactable )
	void Open();
	virtual void Open_Implementation() {}
};
