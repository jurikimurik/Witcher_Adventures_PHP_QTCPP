<?php

use item\Item;

require_once (realpath(dirname(__FILE__).'/../../objects/database/basic/ItemDatabase.php'));

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