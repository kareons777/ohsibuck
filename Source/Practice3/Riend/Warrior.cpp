// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior.h"

// Sets default values
AWarrior::AWarrior()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWarrior::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if( RootComponent )
	{
		// Attach contact function to all bounding components
		GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic( this, &AWarrior::OnOverlapsBegin );
		GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic( this, &AWarrior::OnOverlapsEnd );
	}
}

// Called every frame
void AWarrior::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if( Controller )
	{
		float len = lastInput.Size();
		if( len > 1.f ) lastInput /= len;
		AddMovementInput( GetActorForwardVector(), lastInput.Y );
		AddMovementInput( GetActorRightVector(), lastInput.X );
		// Zero off last input values
		lastInput = FVector2D( 0.f, 0.f );
	}
}

// Called to bind functionality to input
void AWarrior::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent( PlayerInputComponent );
	check( PlayerInputComponent );
	PlayerInputComponent->BindAxis( "Forward", this, &AWarrior::Forward );
	PlayerInputComponent->BindAxis( "Back", this, &AWarrior::Back );
	PlayerInputComponent->BindAxis( "Right", this, &AWarrior::Right );
	PlayerInputComponent->BindAxis( "Left", this, &AWarrior::Left );

	PlayerInputComponent->BindAction( "Jump", IE_Pressed, this, &AWarrior::Jump );

	FInputAxisKeyMapping backKey( "Back", EKeys::Q, 1.f );
	FInputActionKeyMapping jump( "Jump", EKeys::SpaceBar, 0, 0, 0, 0 );

	GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping( backKey );
	UPlayerInput::AddEngineDefinedActionMapping( jump );
}

void AWarrior::MoveForward( float amount )
{
	if( Controller && amount )
	{
		// Moves the player forward by an amount in forward direction
		AddMovementInput( GetActorForwardVector(), amount );
	}
}

void AWarrior::Forward( float amount )
{
	// We use a += of the amount added so that when the other function modifying .Y affects lastInput
	// it won't overwrite with 0's
	lastInput.Y += amount;
}
void AWarrior::Back( float amount )
{
	lastInput.Y += -amount;
}
void AWarrior::Right( float amount )
{
	lastInput.X += amount;
}
void AWarrior::Left( float amount )
{
	lastInput.X += -amount;
}

void AWarrior::OnOverlapsBegin_Implementation( UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult&SweepResult )
{
  UE_LOG(LogTemp, Warning, TEXT( "Overlaps warrior began" ) );
}

void AWarrior::OnOverlapsEnd_Implementation( UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex )
{
  UE_LOG(LogTemp, Warning, TEXT( "Overlaps warrior ended" ) );
}

