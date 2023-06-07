<?php

namespace database\basic;

use item\Item;
use item\ItemType;

class ItemDatabase
{
    private array $data = array();

    public function add(Item $item): bool
    {
        if(!in_array($item,$this->data,true)) {
            $this->data[] = $item;
            return true;
        } else {
            return false;
        }
    }

    public function remove(int $which)
    {
        if($which < count($this->data))
            array_splice($this->data,$which,1);
    }

    public function get(int $id): Item
    {
        foreach ($this->data as $item)
        {
            /** @var Item $item */
            if($item->getId() === $id)
                return $item;
        }

        return new Item(-1, "NONE", new ItemType("NOTHING", "NOTHING"), "NONE", "NONE", 0, array());
    }

    public function removeById(int $id)
    {
        for($i = 0; $i < count($this->data); $i++)
        {
            /** @var Item $item */
            $item = $this->data[$i];
            if($item->getId() === $id)
            {
                $this->remove($i);
            }
        }
    }

    public function update(Item $item)
    {
        $this->removeById($item->getId());
        $this->add($item);
    }


    /**
     * @return array
     */
    public function getData(): array
    {
        return $this->data;
    }

    /**
     * @param array $data
     */
    public function setData(array $data): void
    {
        $this->data = $data;
    }


}