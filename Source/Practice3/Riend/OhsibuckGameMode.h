// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyFirstActor.h"
#include "GameFramework/GameMode.h"
#include "Engine.h"
#include "OhsibuckGameMode.generated.h"

/**
 * 
 */
// 기본 델리게이트
DECLARE_DELEGATE( FStandardDelegateSignature )
// 파라미터 델리게이트
DECLARE_DELEGATE_OneParam( FParamDelegateSignature, FLinearColor )
// 멀티캐스트 델리게이트
DECLARE_MULTICAST_DELEGATE( FMulticastDelegateSignature )
UCLASS()
class PRACTICE3_API AOhsibuckGameMode : public AGameMode
{
	GENERATED_BODY()

	void BeginPlay();

	UPROPERTY()		AMyFirstActor* SpawnedActor;
	UFUNCTION()		void DestroyActorFunction();

public:
	FStandardDelegateSignature MyStandardDelegate;
	FParamDelegateSignature MyParameterDelegate;
	FMulticastDelegateSignature MyMulticastDelegate;

	static AOhsibuckGameMode* GetOhsibuckGameMode( UWorld* pWorld )
	{
		if( pWorld )
			return Cast< AOhsibuckGameMode >( UGameplayStatics::GetGameMode( pWorld ));
		return nullptr;
	}
};
