<?php

namespace item;

class Item extends \DatabaseItem
{
    private ItemType $type;
    private $description;
    private $imageName;
    private $money;
    private $buffs;

    public function __construct($id, $name, $type, $description, $imageName, $money, $buffs)
    {
        parent::__construct($id, $name);
        $this->type = $type;
        $this->description = $description;
        $this->imageName = $imageName;
        $this->money = $money;
        $this->buffs = $buffs;
    }

    /**
     * @return ItemType
     */
    public function getType(): ItemType
    {
        return $this->type;
    }

    /**
     * @param ItemType $type
     */
    public function setType(ItemType $type): void
    {
        $this->type = $type;
    }

    /**
     * @return mixed
     */
    public function getDescription()
    {
        return $this->description;
    }

    /**
     * @param mixed $description
     */
    public function setDescription($description): void
    {
        $this->description = $description;
    }

    /**
     * @return mixed
     */
    public function getImageName()
    {
        return $this->imageName;
    }

    /**
     * @param mixed $imageName
     */
    public function setImageName($imageName): void
    {
        $this->imageName = $imageName;
    }

    /**
     * @return mixed
     */
    public function getMoney()
    {
        return $this->money;
    }

    /**
     * @param mixed $money
     */
    public function setMoney($money): void
    {
        $this->money = $money;
    }

    /**
     * @return mixed
     */
    public function getBuffs()
    {
        return $this->buffs;
    }

    /**
     * @param mixed $buffs
     */
    public function setBuffs($buffs): void
    {
        $this->buffs = $buffs;
    }
}