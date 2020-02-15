// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyFirstActor.h"
#include "GameFramework/GameMode.h"
#include "OhsibuckGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICE3_API AOhsibuckGameMode : public AGameMode
{
	GENERATED_BODY()

	void BeginPlay();

	UPROPERTY()		AMyFirstActor* SpawnedActor;
	UFUNCTION()		void DestroyActorFunction();
};
