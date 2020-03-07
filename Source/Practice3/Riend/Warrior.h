// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine.h"
#include "Warrior.generated.h"

UCLASS()
class PRACTICE3_API AWarrior : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	AWarrior();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector2D lastInput;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward( float amount );
	void Forward( float amount );
	void Back( float amount );
	void Left( float amount );
	void Right( float amount );


	virtual void PostInitializeComponents() override;
	UFUNCTION( BlueprintNativeEvent, Category = Collision )
		void OnOverlapsBegin( UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult&SweepResult );

	UFUNCTION( BlueprintNativeEvent, Category = Collision )
		void OnOverlapsEnd( UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex );
};
