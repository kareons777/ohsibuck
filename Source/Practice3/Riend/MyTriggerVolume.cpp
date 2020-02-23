// Fill out your copyright notice in the Description page of Project Settings.


#include "OhsibuckGameMode.h"
#include "MyTriggerVolume.h"

// Sets default values
AMyTriggerVolume::AMyTriggerVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerZone = CreateDefaultSubobject< UBoxComponent >( "TriggerZone" );
	TriggerZone->SetBoxExtent( FVector( 200, 200, 100 ));
}

// Called when the game starts or when spawned
void AMyTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTriggerVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTriggerVolume::NotifyActorBeginOverlap( AActor* OtherActor )
{
	GEngine->AddOnScreenDebugMessage( -1, 1, FColor::Red, FString::Printf( TEXT( "%s entered me" ), *(OtherActor->GetName())));
	auto TheWorld = GetWorld();
	if( TheWorld != nullptr )
	{
		auto myGameMode = Cast< AOhsibuckGameMode >( UGameplayStatics::GetGameMode( TheWorld ));
		myGameMode->MyStandardDelegate.ExecuteIfBound();
		myGameMode->MyParameterDelegate.ExecuteIfBound( FLinearColor (1, 0, 0, 1 ));
		myGameMode->MyMulticastDelegate.Broadcast();
	}
	OnPlayerEntered.Broadcast();
}

void AMyTriggerVolume::NotifyActorEndOverlap( AActor* OtherActor )
{
	GEngine->AddOnScreenDebugMessage( -1, 1, FColor::Red, FString::Printf( TEXT( "%s left me" ), *(OtherActor->GetName())));
}

