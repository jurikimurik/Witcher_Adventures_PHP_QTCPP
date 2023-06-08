<?php

namespace item;

require_once (realpath(dirname(__FILE__) . '/../database/basic/ItemDatabase.php'));

class Inventory extends \database\basic\ItemDatabase
{
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