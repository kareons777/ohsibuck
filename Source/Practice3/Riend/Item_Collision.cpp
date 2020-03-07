// Fill out your copyright notice in the Description page of Project Settings.


#include "Item_Collision.h"

// Sets default values
AItem_Collision::AItem_Collision( const FObjectInitializer& PCIP ) : Super( PCIP )
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	sphere = PCIP.CreateDefaultSubobject< USphereComponent >( this, TEXT( "Sphere" ));
	sphere->AttachTo( GetRootComponent());
}

void AItem_Collision::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	sphere->OnComponentBeginOverlap.AddDynamic( this, &AItem_Collision::OnOverlapsBegin );
}


// Called when the game starts or when spawned
void AItem_Collision::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem_Collision::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem_Collision::OnOverlapsBegin_Implementation(UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlaps item began"));
}

