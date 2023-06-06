<?php

namespace item;

class ItemType
{
    private $typeName;
    private $typeDescription;

    public function __construct($typeName, $typeDescription) {
        $this->typeName = $typeName;
        $this->typeDescription = $typeDescription;
    }

    /**
     * @return mixed
     */
    public function getTypeName()
    {
        return $this->typeName;
    }

    /**
     * @param mixed $typeName
     */
    public function setTypeName($typeName): void
    {
        $this->typeName = $typeName;
    }

    /**
     * @return mixed
     */
    public function getTypeDescription()
    {
        return $this->typeDescription;
    }

    /**
     * @param mixed $typeDescription
     */
    public function setTypeDescription($typeDescription): void
    {
        $this->typeDescription = $typeDescription;
    }
}