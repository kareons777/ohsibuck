#pragma once

#include "Talker.generated.h"

UINTERFACE()
class PRACTICE3_API UTalker : public UInterface
{
	GENERATED_BODY()
};

class PRACTICE3_API ITalker
{
	GENERATED_BODY()
public:
	UFUNCTION( BlueprintNativeEvent, BlueprintCallable, Category = Talk )
	void StartTalking();
};
