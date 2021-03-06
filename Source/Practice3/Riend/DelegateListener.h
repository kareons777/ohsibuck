// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "DelegateListener.generated.h"

UCLASS()
class PRACTICE3_API ADelegateListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADelegateListener();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION() virtual void EndPlay( const EEndPlayReason::Type EndPlayReason ) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION() void EnableLight();
	UPROPERTY() UPointLightComponent* PointLight;
};
