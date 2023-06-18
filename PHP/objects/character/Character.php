<?php

namespace character;
$ROOT = dirname(__FILE__, 3);
require_once($ROOT.'/objects/basic/DatabaseItem.php');
require_once($ROOT.'/objects/special/Buff.php');
use special\Buff;

class Character extends \DatabaseItem
{
    private string $imageName;
    private Buff $attributes;

    public function __construct(int $id, string $name, string $imageName, Buff $attributes)
    {
        parent::__construct($id, $name);
        $this->imageName = $imageName;
        $this->attributes = $attributes;
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
     * @return Buff
     */
    public function getAttributes(): Buff
    {
        return $this->attributes;
    }

    /**
     * @param Buff $attributes
     */
    public function setAttributes(Buff $attributes): void
    {
        $this->attributes = $attributes;
    }


}