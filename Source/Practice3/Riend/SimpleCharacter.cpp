// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleCharacter.h"

// Sets default values
ASimpleCharacter::ASimpleCharacter() : Super()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyInventory = CreateDefaultSubobject< UInventoryComponent >( "MyInventory" );
	MainCamera = CreateDefaultSubobject< UCameraComponent >( "MainCamera" );
	MainCamera->bUsePawnControlRotation = 0;
}

// Called when the game starts or when spawned
void ASimpleCharacter::BeginPlay()
{
	Super::BeginPlay();
	MainCamera->AttachTo( RootComponent );
}

// Called every frame
void ASimpleCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!MovementInput.IsZero())
	{
		MovementInput *= 100;
		FVector InputVector = FVector( 0, 0, 0 );
		InputVector += GetActorForwardVector() * MovementInput.X * DeltaTime;
		InputVector += GetActorRightVector() * MovementInput.Y * DeltaTime;
		GetCharacterMovement()->AddInputVector( InputVector );
		GEngine->AddOnScreenDebugMessage( -1, 1, FColor::Red, FString::Printf( TEXT( "x- %f, y - %f, z - %f" ), InputVector.X, InputVector.Y, InputVector.Z ));

	}

	if( !CameraInput.IsNearlyZero())
	{
		FRotator NewRotation = GetActorRotation();
		NewRotation.Pitch += CameraInput.Y;
		NewRotation.Yaw += CameraInput.X;
		APlayerController* MyPlayerController = Cast< APlayerController >( GetController());
		if( MyPlayerController != nullptr )
		{
			MyPlayerController->AddYawInput( CameraInput.X );
			MyPlayerController->AddPitchInput( CameraInput.Y );
		}
		SetActorRotation( NewRotation );
	}
}

void ASimpleCharacter::MoveForward( float AxisValue ) { MovementInput.X = FMath::Clamp< float >( AxisValue, - 1.0f, 1.0f ); }
void ASimpleCharacter::MoveRight( float AxisValue ) { MovementInput.Y = FMath::Clamp< float >( AxisValue, - 1.0f, 1.0f ); }
void ASimpleCharacter::PitchCamera( float AxisValue ){ CameraInput.Y = AxisValue; }
void ASimpleCharacter::YawCamera( float AxisValue ){ CameraInput.X = AxisValue; }

// Called to bind functionality to input
void ASimpleCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis( "MoveForward", this, &ASimpleCharacter::MoveForward );
	InputComponent->BindAxis( "MoveRight", this, &ASimpleCharacter::MoveRight );
	InputComponent->BindAxis( "CameraPitch", this, &ASimpleCharacter::PitchCamera );
	InputComponent->BindAxis( "CameraYaw", this, &ASimpleCharacter::YawCamera );

	InputComponent->BindAction( "DropItem", EInputEvent::IE_Pressed, this, &ASimpleCharacter::DropItem );

}

void ASimpleCharacter::DropItem()
{
	if( MyInventory->CurrentInventory.Num() == 0 )
		return;
	AInventoryActor* Item = MyInventory->CurrentInventory.Last();
	MyInventory->RemoveFromInventory( Item );
	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds( false, ItemOrigin, ItemBounds );
	FTransform PutDownLocation = GetTransform() + FTransform( RootComponent->GetForwardVector() * ItemBounds.GetMax());
	Item->PutDown( PutDownLocation );
}

void ASimpleCharacter::NotifyHit( class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit )
{
	AInventoryActor* InventoryItem = Cast< AInventoryActor >( Other );
	if( InventoryItem != nullptr )
		TakeItem( InventoryItem );
}

void ASimpleCharacter::TakeItem( AInventoryActor* InventoryItem )
{
	InventoryItem->PickUp();
	MyInventory->AddToInventory( InventoryItem );
}