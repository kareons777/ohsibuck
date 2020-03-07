// Fill out your copyright notice in the Description page of Project Settings.


#include "OhsibuckGameMode.h"
#include "UserProfile.h"
#include "MyFirstActor.h"
#include "SingleInterfaceActor.h"

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

	// Chatper 7
	FTransform SpawnLocation_SingleInterface;
	ASingleInterfaceActor* SingleInterfaceSpawned = GetWorld()->SpawnActor< ASingleInterfaceActor >( ASingleInterfaceActor::StaticClass(), SpawnLocation_SingleInterface );
	if( SingleInterfaceSpawned->GetClass()->ImplementsInterface( UMyInterface::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage( -1, 1, FColor::Red, TEXT( "Spawned actor implements interfcae!" ));
	}

	for( TActorIterator< AActor > It( GetWorld(), AActor::StaticClass()); It; ++It )
	{
		AActor* Actor = *It;
		IMyInterface* MyInterfaceInstance = Cast< IMyInterface >( Actor );
		if( MyInterfaceInstance )
		{
			MyInterfaceInstances.Add( MyInterfaceInstance );
		}
	}
	GEngine->AddOnScreenDebugMessage( -1, 1, FColor::Red, FString::Printf( TEXT( "%d actors implement the interface" ), MyInterfaceInstances.Num()));
}

void AOhsibuckGameMode::DestroyActorFunction()
{
	if( SpawnedActor != nullptr )
		SpawnedActor->Destroy();
}

void AOhsibuckGameMode::ButtonClicked()
{
	UE_LOG( LogTemp, Warning, TEXT( "UI ButtonClicked" ));
}

// Chapter 6... Àß ¾ÈµÊ.
//void AOhsibuckGameMode::ChangeMenuWidget( TSubclassOf< UUserWidget > NewWidgetClass )
//{
//	if( CurrentWidget != nullptr )
//	{
//		//CurrentWidget->RemoveFromViewport();
//		CurrentWidget = nullptr;
//	}
//	if( NewWidgetClass != nullptr )
//	{
//		//CurrentWidget = CreateWidget< UUserWidget, UWorld >( GetWorld(), NewWidgetClass );
//		//if( CurrentWidget != nullptr )
//		//	CurrentWidget->AddToViewport();
//	}
//}

// Chapter 7
