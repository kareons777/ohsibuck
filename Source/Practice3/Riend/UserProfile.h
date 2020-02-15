// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UserProfile.generated.h" // UPROPERTY, UFUNCTION등의 매크로가 반영된 헤더를 빌드하려면, 이 헤더가 필요하다.( **.generated.h )

/**
 * 
 */
UCLASS( Blueprintable, BlueprintType )
class PRACTICE3_API UUserProfile : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Stats )
	float Armor;
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Stats )
	float HpMax;
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Stats )
	FString Name;
	
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Unit )
	TSubclassOf< UObject > UClassOfPlayer;
	UPROPERTY( EditAnywhere, meta = (MetaClass = "GameMode"), Category = Unit )
	FStringClassReference UClassGameMode;
};
