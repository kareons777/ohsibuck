// Fill out your copyright notice in the Description page of Project Settings.


#include "OhsibuckGameMode.h"
#include "UserProfile.h"
#include "MyFirstActor.h"
#include "Engine.h"

void AOhsibuckGameMode::BeginPlay()
{
	Super::BeginPlay();

	auto world = GetWorld();
	AOhsibuckGameMode* gm = Cast< AOhsibuckGameMode > ( world->GetAuthGameMode());

	if( gm )
	{
		UUserProfile* object = NewObject< UUserProfile >();
		object->ConditionalBeginDestroy();
	}

	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Actor Spawning"));
	UE_LOG( LogTemp, Verbose, TEXT("UMyClass %s entering FireWeapon()"), *GetNameSafe(this));
	FTransform SpawnLocation;
	SpawnedActor = GetWorld()->SpawnActor< AMyFirstActor >( AMyFirstActor::StaticClass(), SpawnLocation );

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer( Timer, this, &AOhsibuckGameMode::DestroyActorFunction, 10 );
}

void AOhsibuckGameMode::DestroyActorFunction()
{
	if( SpawnedActor != nullptr )
		SpawnedActor->Destroy();
}