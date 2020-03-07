#pragma once

#include "Engine.h"

namespace RiendUtil
{
	inline void ODS( FString msg, int32 Key = -1, float TimeToDisplay = -1, FColor Color = FColor::Red )
	{
		GEngine->AddOnScreenDebugMessage( Key, 1, Color, msg);
	}
	inline ConstructorHelpers::FObjectFinder< UStaticMesh > GetBasicShape( FString strShape )
	{
		FString fullString = "StaticMesh'/Engine/BasicShapes/" + strShape + "." + strShape + "'";
		return ConstructorHelpers::FObjectFinder< UStaticMesh >( *fullString );
	}
	template < typename T >
	inline bool IsImplement( UObjectBase* pTarget )
	{
		return pTarget->GetClass()->ImplementsInterface( T::StaticClass());
	}
};
