#pragma once

#include "Riend/RiendCommon.h"
#include "PostBeginPlay.generated.h"


UINTERFACE(meta = (CannotImplementInterfaceInBlueprint))
class PRACTICE3_API UPostBeginPlay : public UInterface
{
	GENERATED_BODY()
};

class PRACTICE3_API IPostBeginPlay
{
	GENERATED_BODY()

public:
	UFUNCTION( BlueprintCallable, Category = Test )
	virtual void OnPostBeginPlay();

};