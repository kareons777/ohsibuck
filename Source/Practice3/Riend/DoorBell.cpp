// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorBell.h"
#include "Riend/Interface/Openable.h"
#include "Riend/RiendCommon.h"

ADoorBell::ADoorBell()
{
	HasBeenPushed = false;
	auto MeshAsset = RiendUtil::GetBasicShape( "Cube" );
	if( MeshAsset.Object != nullptr )
	{
		GetStaticMeshComponent()->SetStaticMesh( MeshAsset.Object );
		GetStaticMeshComponent()->SetGenerateOverlapEvents( true );
	}
	GetStaticMeshComponent()->SetMobility( EComponentMobility::Movable );
	GetStaticMeshComponent()->SetWorldScale3D( FVector( 0.5, 0.5, 0.5 ));
	SetActorEnableCollision( true );
	DoorToOpen = nullptr;
}

bool ADoorBell::CanInteract_Implementation()
{
	return !HasBeenPushed;
}

void ADoorBell::PerformInteract_Implementation()
{
	HasBeenPushed = true;
	if( RiendUtil::IsImplement< UOpenable >( DoorToOpen ))
	{
		IOpenable::Execute_Open( DoorToOpen );
	}
}
