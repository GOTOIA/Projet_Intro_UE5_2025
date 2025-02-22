// Fill out your copyright notice in the Description page of Project Settings.


#include "COpenDoor.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"



/****************************************************************************************************
Description : Constructor, Sets default values for this component's properties
Input : None

Output : None

Note ://

******************************************************************************************************/
UCOpenDoor::UCOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PressurePlate = nullptr;

	//static ConstructorHelpers::FClassFinder<ACharacter>BP_Character(TEXT("Game/BluePrints/BP/BP_PlayerChar"));
	//BP_SPawnPlayer = BP_Character.Class;

	myActor = nullptr;


	fltLastDoorOpenTime=0.f;

	isOpen = false;
	// ...
}


/****************************************************************************************************
Description : Call when game start
Input : None

Output : None

Note ://

******************************************************************************************************/
void UCOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	myActor = GetOwner();

	// ...
	
}


/****************************************************************************************************
Description : Call every frame ,exec openDoor/closeDoor fct
Input : DeltaTime,TickType, ThisFunctionTick

Output : ThisFunctionTick

Note :Delta time is the time between two frames

******************************************************************************************************/
void UCOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);




	if (ensure(PressurePlate)) {

		if (getTotalMassOfActors() >= fltMassTest) {
			openDoor();
			fltLastDoorOpenTime = GetWorld()->GetTimeSeconds();
			//UE_LOG(LogTemp, Warning, TEXT("fltLastDoorOpenTime   : %f"), fltLastDoorOpenTime);
			isOpen = true;

		}
		else if ((timeLastDoorOpen=GetWorld()->GetTimeSeconds()-fltLastDoorOpenTime)>fltDelay && isOpen) {
			//UE_LOG(LogTemp, Warning, TEXT("fltLastDoorOpenTime   : %f"), fltLastDoorOpenTime);
			closeDoor();
			isOpen = false;
			UE_LOG(LogTemp, Warning, TEXT("Time Last Door Open : %f"), timeLastDoorOpen);
		}
		
		//UE_LOG(LogTemp,Warning,TEXT("Is open : %d"),isOpen);


	}

	// ...
}

/****************************************************************************************************
Description : This function calculates the total of the Actors Mass
Input : None

Output : None

Note ://

******************************************************************************************************/

float UCOpenDoor::getTotalMassOfActors()
{

	TArray<AActor*> MyArray;
	float fltTotalMass = 0.f;


	PressurePlate->GetOverlappingActors(MyArray);
	for (class AActor* Actors : MyArray) {

		fltTotalMass = fltTotalMass + Actors->FindComponentByClass<UStaticMeshComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("Find Actors Mass : %f"), fltTotalMass);
	}
	

	
	return fltTotalMass;
}

void UCOpenDoor::openDoor()
{
	
	OnOpenRequest.Broadcast();

	UE_LOG(LogTemp, Warning, TEXT("Open"));
}

void UCOpenDoor::closeDoor()
{

	OnCloseRequest.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Close"));
}

