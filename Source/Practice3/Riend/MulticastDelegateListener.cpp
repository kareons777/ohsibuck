// Fill out your copyright notice in the Description page of Project Settings.

#include "OhsibuckGameMode.h"
#include "MulticastDelegateListener.h"

// Sets default values
AMulticastDelegateListener::AMulticastDelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PointLight = CreateDefaultSubobject< UPointLightComponent >("PointLight");
	RootComponent = PointLight;
}

// Called when the game starts or when spawned
void AMulticastDelegateListener::BeginPlay()
{
	Super::BeginPlay();
	auto pOhsibuckGameMode = AOhsibuckGameMode::GetOhsibuckGameMode( GetWorld());
	if( pOhsibuckGameMode )
		MyDelegateHandle = pOhsibuckGameMode->MyMulticastDelegate.AddUObject( this, &AMulticastDelegateListener::ToggleLight );
}

// Called every frame
void AMulticastDelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMulticastDelegateListener::EndPlay( const EEndPlayReason::Type EndPlayReason )
{
	Super::EndPlay( EndPlayReason );
	auto pOhsibuckGameMode = AOhsibuckGameMode::GetOhsibuckGameMode( GetWorld());
	if( pOhsibuckGameMode )
		pOhsibuckGameMode->MyMulticastDelegate.Remove( MyDelegateHandle );
}
void AMulticastDelegateListener::ToggleLight()
{
	PointLight->ToggleVisibility();
}
