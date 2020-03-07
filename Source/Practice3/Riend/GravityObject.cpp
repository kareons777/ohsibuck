
#include "GravityObject.h"
#include "Engine.h"

void IGravityObject::EnableGravity()
{
	AActor* ThisAsActor = Cast< AActor >( this );
	if( ThisAsActor != nullptr )
	{
		TArray< UPrimitiveComponent* > PrimitiveComponents;
		ThisAsActor->GetComponents( PrimitiveComponents );
		for( UPrimitiveComponent* Component : PrimitiveComponents )
		{
			Component->SetEnableGravity( true );
		}
	}
}

void IGravityObject::DisableGravity()
{
	AActor* ThisAsActor = Cast< AActor >( this );
	if( ThisAsActor != nullptr )
	{
		TArray< UPrimitiveComponent* > PrimitiveComponents;
		ThisAsActor->GetComponents( PrimitiveComponents );
		for( UPrimitiveComponent* Component : PrimitiveComponents )
		{
			Component->SetEnableGravity( false );
		}
	}
}