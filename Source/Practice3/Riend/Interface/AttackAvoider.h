#pragma once

#include "Riend/RiendCommon.h"
#include "AttackAvoider.generated.h"

UINTERFACE()
class PRACTICE3_API UAttackAvoider : public UInterface
{
	GENERATED_BODY()
};

class PRACTICE3_API IAttackAvoider
{
	GENERATED_BODY()

public:
	UFUNCTION( BlueprintImplementableEvent, BlueprintCallable, Category = AttackAvoider )
	void AttackIncoming( AActor* AttackActor );
};