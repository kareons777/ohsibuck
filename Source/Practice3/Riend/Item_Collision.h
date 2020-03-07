// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "Item_Collision.generated.h"

UCLASS()
class PRACTICE3_API AItem_Collision : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem_Collision() {}
	AItem_Collision(const FObjectInitializer& PCIP);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void PostInitializeComponents() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Collisions )
	USphereComponent* sphere;

	UFUNCTION( BlueprintNativeEvent, Category = Collision )
	void OnOverlapsBegin( UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult );
};
