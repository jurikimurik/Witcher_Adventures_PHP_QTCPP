<?php

namespace player;
$ROOT = dirname(__FILE__, 3);
require_once($ROOT.'/objects/character/Character.php');
require_once($ROOT.'/objects/item/Inventory.php');


use character\Character;
use item\Inventory;
use special\Buff;
use item\Item;

class Player extends Character
{
    //------------Basic variables---------------
    private Buff $basicAttributes;
    private Buff $currentAttributes;
    private array $buffs = array();
    private Inventory $inventory;

    //------------Equipped inventory------------
    private Item $weapon;
    private Item $armour;
    private Item $pants;
    private Item $shoes;
    private Item $gloves;
    //------------------------------------------

    public function __construct(Character $character, Inventory $inventory = new Inventory())
    {
        parent::__construct($character->getId(), $character->getName(), $character->getImageName(), $character->getAttributes());
        $this->setBasicAttributes($character->getAttributes());
        $this->inventory = $inventory;

        //Initializing basic fields
        if(!isset($this->inventory))
            $this->inventory = new Inventory();
        $this->weapon = new Item();
        $this->armour = new Item();
        $this->pants = new Item();
        $this->shoes = new Item();
        $this->gloves = new Item();

        $this->updateAttributes();
    }

    /**
     * @return Item
     */
    public function getArmour(): Item
    {
        return $this->armour;
    }

    /**
     * @param Item $armour
     */
    public function setArmour(Item $armour): void
    {
        if($this->armour->getId() === $armour->getId())
            return;

        $this->armour = $armour;
        $this->updateAttributes();
    }

    /**
     * @return Item
     */
    public function getPants(): Item
    {
        return $this->pants;
    }

    /**
     * @param Item $pants
     */
    public function setPants(Item $pants): void
    {
        if($this->pants->getId() === $pants->getId())
            return;

        $this->pants = $pants;
        $this->updateAttributes();
    }

    /**
     * @return Item
     */
    public function getShoes(): Item
    {
        return $this->shoes;
    }

    /**
     * @param Item $shoes
     */
    public function setShoes(Item $shoes): void
    {
        if($this->shoes->getId() === $shoes->getId())
            return;

        $this->shoes = $shoes;
        $this->updateAttributes();
    }

    /**
     * @return Item
     */
    public function getGloves(): Item
    {
        return $this->gloves;
    }

    /**
     * @param Item $gloves
     */
    public function setGloves(Item $gloves): void
    {
        if($this->gloves->getId() === $gloves->getId())
            return;

        $this->gloves = $gloves;
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

        //Adding attributes
        $attributes = $this->getBasicAttributes();
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
        $this->setCurrentAttributes($attributes);
    }

    public function addBuff(Buff $buff): void
    {
        $this->buffs[] = $buff;
        $this->updateAttributes();
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

    function useItemFromInventory(int $id) : void
    {
        $item = $this->inventory->get($id);
        if($item->getId() === -1)
            return;

        $buffs = $item->getBuffs();
        foreach ($buffs as $buff) {
            $this->addBuff($buff);
        }
        $this->inventory->use($id);
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