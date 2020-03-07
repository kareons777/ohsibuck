#pragma once

#include "Riend/RiendCommon.h"
#include "Wearable.generated.h"

UINTERFACE()
class PRACTICE3_API UWearable : public UInterface
{
	GENERATED_BODY()
};

class PRACTICE3_API IWearable
{
	GENERATED_BODY()

public:
	UFUNCTION( BlueprintNativeEvent, BlueprintCallable, Category = Wearable )
	int32 GetStrengthRequirement();
	UFUNCTION( BlueprintNativeEvent, BlueprintCallable, Category = Wearable )
	bool CanEquip( APawn* Wearer );
	UFUNCTION( BlueprintNativeEvent, BlueprintCallable, Category = Wearable )
	void OnEquip( APawn* Wearer );

	virtual void OnEquip_Implementation( APawn* Wearer )
	{
		RiendUtil::ODS("Item being worn");
	}
};