// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicsCube.h"
#include "Engine.h"

// Sets default values
APhysicsCube::APhysicsCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyMesh = CreateDefaultSubobject< UStaticMeshComponent >( "MyMesh" );
	auto MeshAsset = ConstructorHelpers::FObjectFinder< UStaticMesh >( TEXT( "Static mesh'/Engine/BasicShapes/Cube.Cube'"
	));
	if( MeshAsset.Object != nullptr )
		MyMesh->SetStaticMesh( MeshAsset.Object );
	MyMesh->SetMobility( EComponentMobility::Movable );
	MyMesh->SetSimulatePhysics( true );
	SetActorEnableCollision( true );
}

// Called when the game starts or when spawned
void APhysicsCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APhysicsCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

