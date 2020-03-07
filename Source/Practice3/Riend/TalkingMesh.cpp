// Fill out your copyright notice in the Description page of Project Settings.


#include "TalkingMesh.h"
#include "Riend/RiendCommon.h"
// Sets default values
ATalkingMesh::ATalkingMesh() : AStaticMeshActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	auto MeshAsset = RiendUtil::GetBasicShape( "Cube" );
	if( MeshAsset.Object != nullptr )
	{
		GetStaticMeshComponent()->SetStaticMesh( MeshAsset.Object );
		GetStaticMeshComponent()->SetGenerateOverlapEvents( true );
	}
	GetStaticMeshComponent()->SetMobility( EComponentMobility::Movable );
	SetActorEnableCollision( true );
}

void ATalkingMesh::StartTalking_Implementation()
{
	RiendUtil::ODS( "Hello there. What is your name?" );
}
