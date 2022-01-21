// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "characterJob.generated.h"

#include <vector>

UENUM(BlueprintType)
enum jobList {
	CAPTAIN UMETA(DisplayName = "Deez Nuts"),
	HEAD_OF_PERSONNEL UMETA(DisplayName = "Head of Personnel"),
	HEAD_OF_SECURITY UMETA(DisplayName = "Head of Security"),
	CHIEF_ENGINEER UMETA(DisplayName = "Chief Engineer"),
	RESEARCH_DIRECTOR UMETA(DisplayName = "Research Director"),
	ASSITANT UMETA(DisplayName = "Assitant"), // he the bitch role
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ISSAGAME_API UcharacterJob : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UcharacterJob();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<jobList> commandJob;

private:
};
