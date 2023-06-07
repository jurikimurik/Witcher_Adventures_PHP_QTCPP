<?php

namespace database\basic;

use character\Character;
use consequence\Consequence;

class ConsequenceDatabase
{
    private array $data = array();

    public function add(Consequence $consequence): bool
    {
        if(!in_array($consequence,$this->data,true)) {
            $this->data[] = $consequence;
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

    public function get(int $id): Consequence
    {
        foreach ($this->data as $consequence)
        {
            /** @var Consequence $consequence */
            if($consequence->getId() === $id)
                return $consequence;
        }

        return new Consequence(-1, "", false);
    }

    public function removeById(int $id)
    {
        for($i = 0; $i < count($this->data); $i++)
        {
            /** @var Consequence $consequence */
            $consequence = $this->data[$i];
            if($consequence->getId() === $id)
            {
                $this->remove($i);
            }
        }
    }

    public function update(Consequence $consequence)
    {
        $this->removeById($consequence->getId());
        $this->add($consequence);
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