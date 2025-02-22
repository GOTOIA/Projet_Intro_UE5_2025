// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "COpenDoor.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CYCLE_3_BXLS_NL_2021_API UCOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCOpenDoor();

	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	float getTotalMassOfActors();

	void openDoor();

	void closeDoor();

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnOpenRequest;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnCloseRequest;





private :

	UPROPERTY(EditAnyWhere)
	ATriggerVolume *PressurePlate;

	UPROPERTY(EditAnyWhere)
		float fltMassTest;

	AActor *myActor;

	UPROPERTY(EditAnyWhere)
	float fltDelay;

	float fltLastDoorOpenTime;

	bool isOpen;

	float timeLastDoorOpen;

	


	
};
