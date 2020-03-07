// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Riend/RiendCommon.h"
#include "Riend/Interface/Openable.h"
#include "Riend/Interface/Interactable.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICE3_API ADoor : public AStaticMeshActor, public IInteractable, public IOpenable
{
	GENERATED_BODY()
public:
	ADoor();
	UFUNCTION()	virtual bool CanInteract_Implementation() override{ return IInteractable::CanInteract_Implementation(); }
	UFUNCTION() virtual void PerformInteract_Implementation() override;
	UFUNCTION() virtual void Open_Implementation() override;
};
