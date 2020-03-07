// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

ADoor::ADoor()
{
	auto MeshAsset = RiendUtil::GetBasicShape( "Cube" );
	if( MeshAsset.Object != nullptr )
	{
		GetStaticMeshComponent()->SetStaticMesh( MeshAsset.Object );
		GetStaticMeshComponent()->SetGenerateOverlapEvents( true );
	}
	GetStaticMeshComponent()->SetMobility( EComponentMobility::Movable );
	GetStaticMeshComponent()->SetWorldScale3D( FVector( 0.3, 2, 3 ));
	SetActorEnableCollision( true );
}

void ADoor::PerformInteract_Implementation()
{
	RiendUtil::ODS( "The door refuses to budge. Perhpas there is a hidden switch nearby?", -1, 5 );
}

void ADoor::Open_Implementation()
{
	AddActorLocalOffset( FVector( 0, 0, 200 ));
}