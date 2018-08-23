// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReport.h"
#include "BuildingEscape.h"
//UE4.18+ requires this include to work.
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();

	//Gets name
	FString ObjectName = GetOwner()->GetName();
	//FVector TransformPosition = GetOwner()->GetTransform().ToString();
	FString ObjectPos = GetOwner()->GetTransform().GetLocation().ToString();/*FString::SanitizeFloat(TransformPosition.X), FString::SanitizeFloat(TransformPosition.Y)*/
	UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *ObjectName, *ObjectPos); // %s is where the string will be. * before the declared variable because
																		    //UE_LOG expects TCHAR array and a * before the string converts it to this type.
	// ...
	
}


// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

