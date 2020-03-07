#pragma once

#include "Engine.h"
#include "MyInterface.generated.h"


UINTERFACE()
class PRACTICE3_API UMyInterface : public UInterface
{
	GENERATED_BODY()
};

class PRACTICE3_API IMyInterface
{
	GENERATED_BODY()

public:
	virtual FString GetTestName();
};