<?php

namespace player;

use character\Character;
use item\Inventory;
use special\Buff;
use item\Item;

enum EquipmentType {
    case WEAPON;
    case ARMOUR;
    case GLOVES;
    case PANTS;
    case SHOES;
    case NONE;
}

class Player extends Character
{
    //------------Basic variables---------------
    private Buff $basicAttributes;
    private Buff $currentAttributes;
    private array $buffs;
    private Inventory $inventory;

    //------------Equipped inventory------------
    private Item $weapon;
    private Item $armour;
    private Item $pants;
    private Item $shoes;
    private Item $gloves;
    //------------------------------------------

    public function __construct(int $id, string $name, string $imageName, Buff $attributes, Inventory $inventory = new Inventory())
    {
        parent::__construct($id, $name, $imageName, $attributes);
        $this->setBasicAttributes($attributes);
        $this->inventory = $inventory;

        $this->updateAttributes();
    }

    /**
     * @return Buff
     */
    public function getBasicAttributes(): Buff
    {
        return $this->basicAttributes;
    }

    /**
     * @param Buff $basicAttributes
     */
    public function setBasicAttributes(Buff $basicAttributes): void
    {
        $this->basicAttributes = $basicAttributes;
    }



    //------------Basic methods-----------------
    public function updateAttributes(): void
    {
        // Cleaning up everything
        $this->setCurrentAttributes($this->basicAttributes);

        //Adding attributes
        $attributes = $this->getCurrentAttributes();
        foreach($this->weapon->getBuffs() as $buff)
        {
            $attributes->sumBuffAttributes($buff);
        }
        foreach ($this->armour->getBuffs() as $buff)
        {
            $attributes->sumBuffAttributes($buff);
        }
        foreach ($this->pants->getBuffs() as $buff)
        {
            $attributes->sumBuffAttributes($buff);
        }
        foreach ($this->gloves->getBuffs() as $buff)
        {
            $attributes->sumBuffAttributes($buff);
        }
        foreach ($this->shoes->getBuffs() as $buff)
        {
            $attributes->sumBuffAttributes($buff);
        }

        foreach ($this->buffs as $buff)
        {
            $attributes->sumBuffAttributes($buff);
        }
    }

    public function addBuff(Buff $buff): void
    {
        $this->buffs[] = $buff;
    }

    public function decreaseBuffs($count = 1): void
    {
        //Decrease all buffs and automatically deleting them
        for($i = 0; $i < count($this->buffs); $i++)
        {
            $buff = $this->buffs[$i];
            /** @var Buff $buff */
            $buff->durationDecrease($count);
            if($buff->getDuration() <= 0) {
                array_splice($this->buffs,$i, 1);
            } else {
                $this->buffs[$i] = $buff;
            }
        }
    }

    public function equipItem(Item $item, EquipmentType $type = EquipmentType::NONE) : bool
    {
        switch ($type) {
            case EquipmentType::WEAPON:
            {
                if($this->weapon->getId() != -1) {
                    $this->inventory->add($this->weapon);
                }
                $this->weapon = $item;
            }
            case EquipmentType::ARMOUR:
            {
                if($this->armour->getId() != -1) {
                    $this->inventory->add($this->armour);
                }
                $this->armour = $item;
            }
            case EquipmentType::GLOVES:
            {
                if($this->gloves->getId() != -1) {
                    $this->inventory->add($this->gloves);
                }
                $this->gloves = $item;
            }
            case EquipmentType::PANTS:
            {
                if($this->pants->getId() != -1) {
                    $this->inventory->add($this->pants);
                }
                $this->pants = $item;
            }
            case EquipmentType::SHOES:
            {
                if($this->shoes->getId() != -1) {
                    $this->inventory->add($this->shoes);
                }
                $this->shoes = $item;
            }
            case EquipmentType::NONE:
                return false;
        }
        $this->updateAttributes();
        return true;
    }
    //------------------------------------------
    /**
     * @return Item
     */
    public function getWeapon(): Item
    {
        return $this->weapon;
    }

    /**
     * @param Item $weapon
     */
    public function setWeapon(Item $weapon): void
    {
        $this->weapon = $weapon;
    }



    /**
     * @return Buff
     */
    public function getCurrentAttributes(): Buff
    {
        return $this->currentAttributes;
    }

    /**
     * @param Buff $attributes
     */
    public function setCurrentAttributes(Buff $attributes): void
    {
        $this->currentAttributes = $attributes;
    }

    /**
     * @return Inventory
     */
    public function &getInventory(): Inventory
    {
        return $this->inventory;
    }

    /**
     * @param Inventory $inventory
     */
    public function setInventory(Inventory $inventory): void
    {
        $this->inventory = $inventory;
    }


}