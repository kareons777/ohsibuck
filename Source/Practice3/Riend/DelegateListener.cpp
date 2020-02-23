// Fill out your copyright notice in the Description page of Project Settings.

#include "OhsibuckGameMode.h"
#include "DelegateListener.h"

// Sets default values
ADelegateListener::ADelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PointLight = CreateDefaultSubobject<  UPointLightComponent >( "PointLight" );
	RootComponent = PointLight;
	PointLight->SetVisibility( false );
}

// Called when the game starts or when spawned
void ADelegateListener::BeginPlay()
{
	Super::BeginPlay();
	auto TheWorld = GetWorld();
	if( TheWorld != nullptr )
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode( TheWorld );
		AOhsibuckGameMode* MyGameMode = Cast< AOhsibuckGameMode >( GameMode );
		if( MyGameMode != nullptr )
			MyGameMode->MyStandardDelegate.BindUObject( this, &ADelegateListener::EnableLight );
	}
}

void ADelegateListener::EndPlay( const EEndPlayReason::Type EndPlayReason )
{
	Super::EndPlay( EndPlayReason );
	auto TheWorld = GetWorld();
	if( TheWorld != nullptr )
	{
		auto OhshibuckGameMode = Cast< AOhsibuckGameMode >( UGameplayStatics::GetGameMode( TheWorld ));
		if( OhshibuckGameMode )
			OhshibuckGameMode->MyStandardDelegate.Unbind();
	}
}


// Called every frame
void ADelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADelegateListener::EnableLight()
{
	PointLight->SetVisibility( true );
}