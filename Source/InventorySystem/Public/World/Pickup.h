#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/InteractionInterface.h"
#include "Player/InventorySystemCharacter.h"
#include "Pickup.generated.h"

class UItemBase;

UCLASS()
class INVENTORYSYSTEM_API APickup : public AActor, public IInteractionInterface
{
	GENERATED_BODY()

public:	
	APickup();
	
	void InitializePickup(const TSubclassOf<UItemBase> BaseClass, const int32 InQuantity);

	void InitializeDrop(UItemBase* ItemToDrop, const int32 InQuantity);

	FORCEINLINE UItemBase* GetItemData() {return ItemReference;};

	virtual void BeginFocus() override;
	virtual void EndFocus() override;
	
protected:

	UPROPERTY(VisibleAnywhere, Category = "Pickup | Components")
	UStaticMeshComponent* PickupMesh;

	UPROPERTY(VisibleAnywhere, Category = "Pickup | Item Reference")
	UItemBase* ItemReference;

	UPROPERTY(VisibleInstanceOnly, Category = "Pickup | Interaction Data")
	FInteractableData InstanceInteractableData;

	UPROPERTY(EditInstanceOnly, Category = "Pickup | Item Initialization")
	int32 ItemQuantity;

	UPROPERTY(EditInstanceOnly, Category = "Pickup | Item Initialization")
	FDataTableRowHandle ItemRowHandle;
	
	virtual void BeginPlay() override;

	virtual void Interact(AInventorySystemCharacter* PlayerCharacter) override;

	void TakePickup(const AInventorySystemCharacter* Taker);

	void UpdateInteractableData();
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};
