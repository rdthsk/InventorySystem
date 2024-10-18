#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

UENUM(BlueprintType)
enum EItemAddResult : uint8
{
	IAR_NoItemAdded UMETA(DisplayName = "No item Added"),
	IAR_PartialAmountItemAdded UMETA(DisplayName = "Partial amount of items added"),
	IAR_AllItemAdded UMETA(DisplayName = "All of items added"),
};

USTRUCT(BlueprintType)
struct FItemAddResult
{
	GENERATED_BODY()

	FItemAddResult() :
	ActualAmountAdded(0),
	OperationResult(IAR_NoItemAdded),
	ResultMessage(FText::GetEmpty())
	{};

	//Actual amount of item that was added to the inventory
	UPROPERTY(BlueprintReadOnly, Category = "Item Add Result")
	int32 ActualAmountAdded;

	//Enum representing the end state of an add item operation
	UPROPERTY(BlueprintReadOnly, Category = "Item Add Result")
	TEnumAsByte<EItemAddResult> OperationResult;

	//Informational message that can be passed with the result
	UPROPERTY(BlueprintReadOnly, Category = "Item Add Result")
	FText ResultMessage;
	
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORYSYSTEM_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventoryComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

	virtual void BeginPlay() override;
};
