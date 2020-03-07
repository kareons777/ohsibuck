// Fill out your copyright notice in the Description page of Project Settings.


#include "TalkingPawn.h"

ATalkingPawn::ATalkingPawn()
{
	// 이 캐릭터가 Tick()을 매프레임 호출하도록 한다. 원하지 않는다면, 성능을 향상시키기 위해 이 옵션을 끌 수 있다.
	PrimaryActorTick.bCanEverTick = true;
	TalkCollider = CreateDefaultSubobject< UBoxComponent >( "TalkCollider" );
	TalkCollider->SetBoxExtent( FVector ( 200, 200, 100 ));
	TalkCollider->OnComponentBeginOverlap.AddDynamic( this, &ATalkingPawn::OnTalkOverlap );
	TalkCollider->AttachTo( RootComponent );
}

// Called when the game starts or when spawned
void ATalkingPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATalkingPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATalkingPawn::OnTalkOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,  int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult )
{
	if ( OtherActor->GetClass()->ImplementsInterface( UTalker::StaticClass()))
	{
		ITalker::Execute_StartTalking( OtherActor );
	}
}