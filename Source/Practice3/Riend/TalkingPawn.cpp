// Fill out your copyright notice in the Description page of Project Settings.


#include "TalkingPawn.h"

ATalkingPawn::ATalkingPawn()
{
	// �� ĳ���Ͱ� Tick()�� �������� ȣ���ϵ��� �Ѵ�. ������ �ʴ´ٸ�, ������ ����Ű�� ���� �� �ɼ��� �� �� �ִ�.
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