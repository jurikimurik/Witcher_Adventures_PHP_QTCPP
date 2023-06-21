<?php

namespace item;
use database\basic\ItemDatabase;

$ROOT = dirname(__FILE__, 3);
require_once($ROOT.'/objects/database/basic/ItemDatabase.php');

class Inventory extends ItemDatabase
{

    public function __construct(array $itemTable = array())
    {
        foreach ($itemTable as $item)
        {
            /** @var Item $item */
            $this->add($item);
        }
    }

    public function count() : int
    {
        return count($this->data);
    }

    public function use(int $id) : Item
    {
        //Searching for item and return
        foreach ($this->data as $item)
        {
            /** @var Item $item */
            if($id === $item->getId()) {
                $this->removeById($id);
                return $item;
            }
        }

        //If there is no such item, return default item
        return new Item();
    }
}