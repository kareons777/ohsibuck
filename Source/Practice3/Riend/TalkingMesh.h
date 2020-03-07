// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Riend/Interface/Talker.h"
#include "TalkingMesh.generated.h"

UCLASS()
class PRACTICE3_API ATalkingMesh : public AStaticMeshActor, public ITalker
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATalkingMesh();
	void StartTalking_Implementation();

};
