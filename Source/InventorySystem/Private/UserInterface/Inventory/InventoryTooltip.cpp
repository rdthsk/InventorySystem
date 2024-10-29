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

	switch (ItemBeingHovered->ItemQuality)
	{
	case EItemQuality::Shoddy:
		ItemName->SetColorAndOpacity(FLinearColor::Gray);
		break;
	case EItemQuality::Common:
		ItemName->SetColorAndOpacity(FLinearColor::White);
		break;
	case EItemQuality::Quality:
		ItemName->SetColorAndOpacity(FLinearColor(0.0f, 0.51f, 0.169f));
		break;
	case EItemQuality::Mastercrafted:
		ItemName->SetColorAndOpacity(FLinearColor(0.0f, 0.4f, 0.75f));
		break;
	case EItemQuality::Grandmaster:
		ItemName->SetColorAndOpacity(FLinearColor(1.0f, 0.45f, 0.0f));
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
