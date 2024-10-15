// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemDataStructs.h"
#include "ItemBase.generated.h"

class AInventorySystemCharacter;
/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UItemBase : public UObject
{
	GENERATED_BODY()

public:

	/*UPROPERTY()
	UInventoryComponent* OwningInventory;*/
	
	UPROPERTY(VisibleAnywhere, Category = "Item Data", meta = (UIMin = 1, UIMax = 100))
	int32 Quantity;
	
	UPROPERTY(EditAnywhere, Category = "Item Data")
	FName ID;
	
	UPROPERTY(EditAnywhere, Category = "Item Data")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	EItemQuality ItemQuality;

	UPROPERTY(EditAnywhere, Category="Item Data")
	FItemStatistics ItemStatistics;

	UPROPERTY(EditAnywhere, Category="Item Data")
	FItemTextData TextData;

	UPROPERTY(EditAnywhere, Category="Item Data")
	FItemAssetData AssetData;

	UPROPERTY(EditAnywhere, Category="Item Data")
	FItemNumericData NumericData;

	UItemBase();

	UItemBase* CreateItemCopy() const;

	UFUNCTION(Category = "Item")
	FORCEINLINE float GetItemStackWeight() const { return Quantity * NumericData.Weight;}

	UFUNCTION(Category = "Item")
	FORCEINLINE float GetItemSingleWeight() const { return NumericData.Weight;}

	UFUNCTION(Category = "Item")
	FORCEINLINE float IsFullItemStack() const { return Quantity == NumericData.MaxStackSize;}

	UFUNCTION(Category = "Item")
	void SetQuantity(int32 NewQuantity);

	UFUNCTION(Category = "Item")
	virtual void Use(AInventorySystemCharacter* Character);

protected:
	bool operator==(const FName& OtherID) const
	{
		return ID == OtherID;	
	}
};
