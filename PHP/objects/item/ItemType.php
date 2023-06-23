<?php

namespace item;

class ItemType
{
    private string $typeName;
    private string $typeDescription;

    public function __construct(string $typeName, string $typeDescription) {
        $this->typeName = $typeName;
        $this->typeDescription = $typeDescription;
    }

    /**
     * @return string
     */
    public function getTypeName(): string
    {
        return $this->typeName;
    }

    /**
     * @param string $typeName
     */
    public function setTypeName(string $typeName): void
    {
        $this->typeName = $typeName;
    }

    /**
     * @return string
     */
    public function getTypeDescription(): string
    {
        return $this->typeDescription;
    }

    /**
     * @param string $typeDescription
     */
    public function setTypeDescription(string $typeDescription): void
    {
        $this->typeDescription = $typeDescription;
    }


}