// Fill out your copyright notice in the Description page of Project Settings.


#include "CPositionReport.h"

// Sets default values for this component's properties
UCPositionReport::UCPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCPositionReport::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FString FName = GetOwner()->GetName();
	FString FPosition = GetOwner()->GetTransform().GetLocation().ToString();
	FString FRotation = GetOwner()->GetTransform().GetRotation().ToString();


	UE_LOG(LogTemp, Warning, TEXT("Player_ID :%s Position : %s Rotation : %s"),
		*FName, *FPosition, *FRotation);

}

