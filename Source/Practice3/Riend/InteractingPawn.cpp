// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractingPawn.h"
#include "Riend/Interface/Interactable.h"
#include "Riend/RiendCommon.h"

void AInteractingPawn::TryInteract()
{
	APlayerController* MyController = Cast< APlayerController >( Controller );
	if( MyController )
	{
		APlayerCameraManager* MyCameraManager = MyController->PlayerCameraManager;
		auto StartLocation = MyCameraManager->GetCameraLocation();
		auto EndLocation = MyCameraManager->GetCameraLocation() + ( MyCameraManager->GetActorForwardVector() * 100 );
		FHitResult HitResult;
		GetWorld()->SweepSingleByObjectType( HitResult, StartLocation, EndLocation, 
			FQuat::Identity, FCollisionObjectQueryParams( FCollisionObjectQueryParams::AllObjects ), 
			FCollisionShape::MakeSphere( 25 ), FCollisionQueryParams( FName( "Interaction" ), true, this ));
		if( HitResult.Actor != nullptr )
		{
			if( RiendUtil::IsImplement< UInteractable >( HitResult.Actor.Get()))
			{
				if( IInteractable::Execute_CanInteract( HitResult.Actor.Get()))
				{
					IInteractable::Execute_PerformInteract( HitResult.Actor.Get());
				}
			}
		}
	}
}

void AInteractingPawn::SetupPlayerInputComponent( UInputComponent* InputComponent )
{
	Super::SetupPlayerInputComponent( InputComponent );
	InputComponent->BindAction( "Interact", IE_Released, this, &AInteractingPawn::TryInteract );
}