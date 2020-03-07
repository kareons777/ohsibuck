#include "Riend/Interface/Selectable.h"
#include "Engine.h"

bool ISelectable::IsSelectable()
{
	GEngine->AddOnScreenDebugMessage( -1, 1, FColor::Green, "Selectable" );
	return true;
}

bool ISelectable::TrySelect()
{
	GEngine->AddOnScreenDebugMessage( -1, 1, FColor::Green, "Accepting Selection");
	return true;
}

void ISelectable::Deselect()
{
	unimplemented();
}