// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "attributesComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ISSAGAME_API UattributesComponent : public UActorComponent
{
    GENERATED_BODY()

public:    
    // Sets default values for this component's properties
    UattributesComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int maxHealth;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int maxLungCapacity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        bool isDead;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        bool isCritical;

    UFUNCTION(BlueprintCallable)
        int getHealth();

    UFUNCTION(BlueprintCallable)
        int setHealth(int newHealthValue);

    UFUNCTION(BlueprintCallable)
        int getLungCapacity();

    UFUNCTION(BlueprintCallable)
        int setLungCapacity(int newLungCapacityValue);

private:
    int health;
    int lungCapacity;

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:    
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};