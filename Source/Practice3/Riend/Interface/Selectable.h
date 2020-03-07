#pragma once

#include "Selectable.generated.h"

/**  */
UINTERFACE()
class PRACTICE3_API USelectable : public UInterface
{
	GENERATED_BODY()
};

class PRACTICE3_API ISelectable
{
	GENERATED_BODY()

public:
	virtual bool IsSelectable();
	virtual bool TrySelect();
	virtual void Deselect();
};