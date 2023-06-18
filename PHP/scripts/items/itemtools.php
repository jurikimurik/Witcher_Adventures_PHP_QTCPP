<?php
$ROOT = $ROOT = dirname(__FILE__, 3);
use item\Item;

require_once($ROOT.'/objects/database/basic/ItemDatabase.php');
require_once($ROOT.'/objects/item/Item.php');

function getItemsByType(\database\basic\ItemDatabase $database, string $type) : array
{
    $items = array();
    $type = strtolower($type);

    foreach ($database->getData() as $item)
    {
        /** @var Item $item */
        if(str_contains(strtolower($item->getType()->getTypeName()), $type))
            $items[] = $item;
    }

    return $items;
}

function getListOfItemsByType(\player\Player $player, Item $equippedItem, string $itemType) : string
{
    if($equippedItem->getId() <= -1)
    {
        $text = '<option value="">Brak</option>';
    } else {
        $text = '<option value="'.$equippedItem->getId().'">'.$equippedItem->getName().'</option>';
    }


    foreach (getItemsByType($player->getInventory(), $itemType) as $item)
    {
        /** @var Item $item */
        if($item->getId() != $equippedItem->getId())
            $text = $text . '<option value="'.$item->getId().'">'.$item->getName().'</option>';
    }
    return $text;
}