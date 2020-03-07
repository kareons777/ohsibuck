#pragma once

#include "Riend/Interface/Killable.h"
#include "Undead.generated.h"

UINTERFACE( meta = ( CannotImplementInterfaceInBlueprint ))
class PRACTICE3_API UUndead : public UKillable
{
	GENERATED_BODY()
};

class PRACTICE3_API IUndead : public IKillable
{
	GENERATED_BODY()

public:
	virtual bool IsDead() override;
	virtual void Die() override;

	virtual void Turn();
	virtual void Banish();
};