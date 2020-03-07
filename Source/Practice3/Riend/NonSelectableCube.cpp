// Fill out your copyright notice in the Description page of Project Settings.
#include "NonSelectableCube.h"
#include "Engine.h"

bool ANonSelectableCube::IsSelectable()
{
	GEngine->AddOnScreenDebugMessage( -1, 1, FColor::Blue, "Not Selectable" );
	return false;
}

bool ANonSelectableCube::TrySelect()
{
	GEngine->AddOnScreenDebugMessage( -1, 1, FColor::Blue, "Refusing Selectable" );
	return false;
}

void ANonSelectableCube::Deselect()
{
	unimplemented();
}

void ANonSelectableCube::NotifyHit( class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit )
{
	if( ANonSelectableCube::IsSelectable())
		TrySelect();
}