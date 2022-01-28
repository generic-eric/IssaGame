// Fill out your copyright notice in the Description page of Project Settings.


#include "attributesComponent.h"

// Sets default values for this component's properties
UattributesComponent::UattributesComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// Set your defaults in blueprint
	maxHealth = 0;
	health = maxHealth;
	maxLungCapacity = 0;
	lungCapacity = maxLungCapacity;
	isDead = true;
	isCritical = true;

	// ...
}


int UattributesComponent::getHealth()
{
	return health;
}

int UattributesComponent::setHealth(int newHealthValue)
{
	if (newHealthValue > maxHealth)
	{
		newHealthValue = maxHealth;
	}
	else
	{
		health = newHealthValue;
	}

	return health;
}

int UattributesComponent::getLungCapacity()
{
	return lungCapacity;
}

int UattributesComponent::setLungCapacity(int newLungCapacityValue)
{
	if (newLungCapacityValue > maxLungCapacity)
	{
		newLungCapacityValue = maxLungCapacity;
	}
	else
	{
		lungCapacity = newLungCapacityValue;
	}

	return lungCapacity;
}

// Called when the game starts
void UattributesComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UattributesComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}