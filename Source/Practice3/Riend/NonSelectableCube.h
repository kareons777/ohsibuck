// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Riend/SelectableCube.h"
#include "NonSelectableCube.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICE3_API ANonSelectableCube : public ASelectableCube
{
	GENERATED_BODY()

	virtual bool IsSelectable() override;
	virtual bool TrySelect() override;
	virtual void Deselect() override;

	virtual void NotifyHit( class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit ) override;
};
