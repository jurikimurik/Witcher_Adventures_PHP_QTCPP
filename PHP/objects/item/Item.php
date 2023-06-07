<?php

namespace item;

require_once(realpath(dirname(__FILE__) . '/../basic/DatabaseItem.php'));

class Item extends \DatabaseItem
{
    private ItemType $type;
    private string $description;
    private string $imageName;
    private int $money;
    private array $buffs;

    public function __construct(int $id, string $name, ItemType $type, string $description, string $imageName, int $money, array $buffs)
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
     * @return string
     */
    public function getDescription(): string
    {
        return $this->description;
    }

    /**
     * @param string $description
     */
    public function setDescription(string $description): void
    {
        $this->description = $description;
    }

    /**
     * @return string
     */
    public function getImageName(): string
    {
        return $this->imageName;
    }

    /**
     * @param string $imageName
     */
    public function setImageName(string $imageName): void
    {
        $this->imageName = $imageName;
    }

    /**
     * @return int
     */
    public function getMoney(): int
    {
        return $this->money;
    }

    /**
     * @param int $money
     */
    public function setMoney(int $money): void
    {
        $this->money = $money;
    }

    /**
     * @return array
     */
    public function getBuffs(): array
    {
        return $this->buffs;
    }

    /**
     * @param array $buffs
     */
    public function setBuffs(array $buffs): void
    {
        $this->buffs = $buffs;
    }


}