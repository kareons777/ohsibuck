#pragma once

#include "Engine.h"
#include "Killable.generated.h"


UINTERFACE( meta = ( CannotImplementInterfaceInBlueprint ))
class PRACTICE3_API UKillable : public UInterface
{
	GENERATED_BODY()
};

class PRACTICE3_API IKillable
{
	GENERATED_BODY()

public:
	UFUNCTION( BlueprintCallable, Category = Killable )
	virtual bool IsDead();
	UFUNCTION( BlueprintCallable, Category = Kiallable )
	virtual void Die();
};