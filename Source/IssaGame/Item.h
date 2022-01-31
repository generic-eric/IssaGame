// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ISSAGAME_API UItem : public UObject
{
	GENERATED_BODY()

public:
    //UPROPERTY(EditAnywhere, BlueprintReadWrite)
    //   int ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FName Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        UTexture2D* Icon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        USkeletalMesh* Mesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int maxStackSize;

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
        void useItem();
	
};

/*
UCLASS(Blueprintable, BlueprintType)
class ISSAGAME_API UItemData : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TSubclassOf<class UItem> itemRef;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int quantity;
};


USTRUCT(BlueprintType)
struct FItemDatabase : public FTableRowBase
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TSubclassOf<class UItemData> itemDataRef;
};
*/

UCLASS(Blueprintable, BlueprintType)
class ISSAGAME_API UItemConsumeble : public UItem
{
    GENERATED_BODY()

public:
    void useItem();
};