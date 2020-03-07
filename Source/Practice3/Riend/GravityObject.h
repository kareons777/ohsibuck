#pragma once

#include "GravityObject.generated.h"

/**  */
UINTERFACE()
class PRACTICE3_API UGravityObject : public UInterface
{
	GENERATED_BODY()
};

class PRACTICE3_API IGravityObject
{
	GENERATED_BODY()

public:
	virtual void EnableGravity();
	virtual void DisableGravity();
};