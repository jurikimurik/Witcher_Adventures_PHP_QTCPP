<?php

namespace database\basic;

use special\Attributes;
use special\Buff;
use character\Character;

class CharacterDatabase
{
    private array $data = array();

    public function add(Character $character): bool
    {
        if(!in_array($character,$this->data,true)) {
            $this->data[] = $character;
            return true;
        } else {
            return false;
        }
    }

    public function remove(int $which): void
    {
        if($which < count($this->data))
            array_splice($this->data,$which,1);
    }

    public function get(int $id): Character
    {
        foreach ($this->data as $character)
        {
            /** @var Character $character */
            if($character->getId() === $id)
                return $character;
        }

        return new Character(-1, "", "", new Buff("", 0, new Attributes(array())));
    }

    public function removeById(int $id): void
    {
        for($i = 0; $i < count($this->data); $i++)
        {
            /** @var Character $character */
            $character = $this->data[$i];
            if($character->getId() === $id)
            {
                $this->remove($i);
            }
        }
    }

    public function update(Character $character): void
    {
        $this->removeById($character->getId());
        $this->add($character);
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