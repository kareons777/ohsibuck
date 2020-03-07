
#include "Riend/Interface/Killable.h"
#include "Engine.h"

bool IKillable::IsDead()
{
	return false;
}

void IKillable::Die()
{
	GEngine->AddOnScreenDebugMessage( -1, 1, FColor::Red, "Arrrgh" );
	AActor* Me = Cast< AActor >( this );
	if (Me)
	{
		Me->Destroy();
	}
}