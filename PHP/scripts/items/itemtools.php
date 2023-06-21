<?php
$ROOT = $ROOT = dirname(__FILE__, 3);

use database\basic\ItemDatabase;
use item\Item;
use player\Player;

require_once($ROOT.'/objects/database/basic/ItemDatabase.php');
require_once($ROOT.'/objects/item/Item.php');

function isArmour(Item $item) : bool
{
    $typeName = $item->getType()->getTypeName();
    if(str_contains(strtolower($typeName), "armour") ||
        str_contains(strtolower($typeName), "pants") ||
        str_contains(strtolower($typeName), "gloves") ||
        str_contains(strtolower($typeName), "shoes"))

        return true;
    else
        return false;
}

function getItemsByType(ItemDatabase $database, string $type) : array
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

function getListOfItemsByType(Player $player, Item $equippedItem, string $itemType) : string
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