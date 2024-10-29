#include "UserInterface/Inventory/InventoryTooltip.h"

#include "Components/TextBlock.h"
#include "Items/ItemBase.h"
#include "UserInterface/Inventory/InventoryItemSlot.h"

void UInventoryTooltip::NativeConstruct()
{
	Super::NativeConstruct();

	UItemBase* ItemBeingHovered = InventorySlotBeingHovered->GetItemReference();

	switch (ItemBeingHovered->ItemType)
	{

		case EItemType::Armor:
			break;
		
		case EItemType::Weapon:
			break;
		
		case EItemType::Shield:
			break;
		
		case EItemType::Spell:
			break;
		
		case EItemType::Consumable:
			ItemType->SetText(FText::FromString("Consumable"));
			DamageValue->SetVisibility(ESlateVisibility::Collapsed);
			ArmorRating->SetVisibility(ESlateVisibility::Collapsed);
			/*StackWeight->SetVisibility(ESlateVisibility::Collapsed);
			MaxStackSize->SetVisibility(ESlateVisibility::Collapsed);*/
			break;
		
		case EItemType::Quest:
			break;
		
		case EItemType::Mundane:
			ItemType->SetText(FText::FromString("Mundane Item"));
			DamageValue->SetVisibility(ESlateVisibility::Collapsed);
			ArmorRating->SetVisibility(ESlateVisibility::Collapsed);
			UsageText->SetVisibility(ESlateVisibility::Collapsed);
			/*StackWeight->SetVisibility(ESlateVisibility::Collapsed);
			MaxStackSize->SetVisibility(ESlateVisibility::Collapsed);*/
			break;

		default:
			break;
	}

	ItemName->SetText(ItemBeingHovered->TextData.Name);
	DamageValue->SetText(FText::AsNumber(ItemBeingHovered->ItemStatistics.DamageValue));
	ArmorRating->SetText(FText::AsNumber(ItemBeingHovered->ItemStatistics.ArmorRating));
	UsageText->SetText(ItemBeingHovered->TextData.UsageText);
	ItemDescription->SetText(ItemBeingHovered->TextData.Description);

	const FString WeightInfo = {"Weight: " + FString::SanitizeFloat(ItemBeingHovered->GetItemStackWeight())};
	StackWeight->SetText(FText::FromString(WeightInfo));
	
	if(ItemBeingHovered->NumericData.bIsStackable)
	{
		const FString StackInfo = {"Max stack size: " + FString::FromInt(ItemBeingHovered->NumericData.MaxStackSize)};

		MaxStackSize->SetText(FText::FromString(StackInfo));
	}
	else
	{
		MaxStackSize->SetVisibility(ESlateVisibility::Collapsed);
	}
}
