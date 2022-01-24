// Fill out your copyright notice in the Description page of Project Settings.


#include "characterJob.h"

// Sets default values for this component's properties
UcharacterJob::UcharacterJob()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	job_ = ASSISTANT;
}


// Called when the game starts
void UcharacterJob::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UcharacterJob::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UcharacterJob::setJob(TEnumAsByte<JobList> job)
{
	job_ = job;
	jobCategoryList_ = categoryMap_[job_];
}

TEnumAsByte<JobList> UcharacterJob::getJob()
{
	return job_;
}

UcharacterJob::CategoryList UcharacterJob::getJobCategoryList()
{
	return jobCategoryList_;
}
