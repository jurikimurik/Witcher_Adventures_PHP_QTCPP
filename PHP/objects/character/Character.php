<?php

namespace character;

class Character extends \DatabaseItem
{
    private $imageName;
    private Buff $attributes;

    public function __construct($id, $name, $imageName, $attributes)
    {
        parent::__construct($id, $name);
        $this->imageName = $imageName;
        $this->attributes = $attributes;
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