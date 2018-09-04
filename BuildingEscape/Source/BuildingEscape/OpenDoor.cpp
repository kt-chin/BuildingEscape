// Copyright Kuan-Ting Chin 2018

#include "OpenDoor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Classes/GameFramework/Actor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

	// ...
	
}

void UOpenDoor::OpenDoor()
{
	FRotator NewRotation = FRotator(0.f, 90.f, 0.f);
	AActor* Owner = GetOwner(); // Actor variable thats a pointer
	Owner->SetActorRotation(NewRotation, ETeleportType::None);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Poll the trigger volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		//if the ActorThatOpens is in the volume, then open door.
		OpenDoor();
	}


	// ...
}

