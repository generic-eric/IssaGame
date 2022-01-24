// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <unordered_map>
#include <vector>

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "characterJob.generated.h"



UENUM(BlueprintType)
enum JobList {
	CAPTAIN                UMETA(DisplayName = "Captain"),
	HEAD_OF_PERSONNEL      UMETA(DisplayName = "Head of Personnel"),
	HEAD_OF_SECURITY       UMETA(DisplayName = "Head of Security"),
	CHIEF_ENGINEER         UMETA(DisplayName = "Chief Engineer"),
	RESEARCH_DIRECTOR      UMETA(DisplayName = "Research Director"),
	CHIEF_MEDICAL_OFFICER  UMETA(DisplayName = "Chief Medical Officer"),
	SECURITY_OFFICER       UMETA(DisplayName = "Security Officer"),
	WARDEN                 UMETA(DisplayName = "Warden"),
	DETECTIVE              UMETA(DisplayName = "Detective"),
	STATION_ENGINEER       UMETA(DisplayName = "Station Engineer"),
	ATMOSPHERIC_TECHNICIAN UMETA(DisplayName = "Atmospheric Technician"),
	GENETICIST             UMETA(DisplayName = "Geneticist"),
	SCIENTIST              UMETA(DisplayName = "Scientist"),
	ROBOTICIST             UMETA(DisplayName = "Roboticist"),
	MEDICAL_DOCTOR         UMETA(DisplayName = "Medical Doctor"),
	PARAMEDIC              UMETA(DisplayName = "Paramedic"),
	CHEMIST                UMETA(DisplayName = "Chemist"),
	VIROLOGIST             UMETA(DisplayName = "Virologist"),
	QUARTERMASTER          UMETA(DisplayName = "Quartermaster"),
	CARGO_TECHNICIAN       UMETA(DisplayName = "Cargo Technician"),
	SHAFT_MINER            UMETA(DisplayName = "Shaft Miner"),
	JANITOR                UMETA(DisplayName = "Janitor"),
	BARTENDER              UMETA(DisplayName = "Bartender"),
	COOK                   UMETA(DisplayName = "Cook"),
	ASSISTANT              UMETA(DisplayName = "Assistant"),
};

UENUM(BlueprintType)
enum JobCategory {
	COMMAND     UMETA(DisplayName = "Command"),
	SECURITY    UMETA(DisplayName = "Security"),
	ENGINEERING UMETA(DisplayName = "Engineering"),
	SCIENCE     UMETA(DisplayName = "Science"),
	MEDICAL     UMETA(DisplayName = "Medical"),
	SUPPLY      UMETA(DisplayName = "Supply"),
	SERVICE     UMETA(DisplayName = "Service"),
	ANTAGONISTS UMETA(DisplayName = "Antagonists"),
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
	// type declaration for job category list
	typedef std::vector<TEnumAsByte<JobCategory>> CategoryList;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Function to set the job for this character
	void setJob(TEnumAsByte<JobList> job);

	TEnumAsByte<JobList> getJob();

	CategoryList getJobCategoryList();


	// member variabel to hold the character's job
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<JobList> job_;

private:
	std::unordered_map<JobList, CategoryList> categoryMap_ = {
		{CAPTAIN               , CategoryList{COMMAND}}, 
		{HEAD_OF_PERSONNEL     , CategoryList{COMMAND, SUPPLY, SERVICE}},
		{HEAD_OF_SECURITY      , CategoryList{COMMAND, SECURITY}}, 
		{CHIEF_ENGINEER        , CategoryList{COMMAND, ENGINEERING}},
		{RESEARCH_DIRECTOR     , CategoryList{COMMAND, SCIENCE}}, 
		{CHIEF_MEDICAL_OFFICER , CategoryList{COMMAND, MEDICAL}}, 
		{SECURITY_OFFICER      , CategoryList{COMMAND, SECURITY}}, 
		{WARDEN                , CategoryList{SECURITY}}, 
		{DETECTIVE             , CategoryList{SECURITY}}, 
		{STATION_ENGINEER      , CategoryList{ENGINEERING}},
		{ATMOSPHERIC_TECHNICIAN, CategoryList{ENGINEERING}},
		{GENETICIST            , CategoryList{SCIENCE}},
		{SCIENTIST             , CategoryList{SCIENCE}},
		{ROBOTICIST            , CategoryList{SCIENCE}},
		{MEDICAL_DOCTOR        , CategoryList{MEDICAL}}, 
		{PARAMEDIC             , CategoryList{MEDICAL}}, 
		{CHEMIST               , CategoryList{MEDICAL}},  
		{VIROLOGIST            , CategoryList{MEDICAL}},
		{QUARTERMASTER         , CategoryList{SUPPLY}}, 
		{CARGO_TECHNICIAN      , CategoryList{SUPPLY}},   
		{SHAFT_MINER           , CategoryList{SUPPLY}}, 
		{JANITOR               , CategoryList{SERVICE}}, 
		{BARTENDER             , CategoryList{SERVICE}}, 
		{COOK                  , CategoryList{SERVICE}}, 
		{ASSISTANT             , CategoryList{SERVICE}},   
	};

	// Job category
	CategoryList jobCategoryList_;
};
