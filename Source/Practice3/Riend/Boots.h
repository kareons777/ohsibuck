// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Riend/Interface/Wearable.h"
#include "Boots.generated.h"

UCLASS()
class PRACTICE3_API ABoots : public AActor, public IWearable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoots();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnEquip_Implementation( APawn* Wearer ) override
	{
		IWearable::OnEquip_Implementation( Wearer );
	}
	virtual bool CanEquip_Implementation( APawn* Wearer ) override
	{
		return IWearable::CanEquip_Implementation( Wearer );
	}
	virtual int32 GetStrengthRequirement_Implementation() override
	{
		return IWearable::GetStrengthRequirement_Implementation();
	}
};
