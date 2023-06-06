<?php

namespace special;

class Attributes
{
    private $values = array();
    public function __construct($values)
    {
        $this->values = $values;
    }

    /**
     * @param array $values
     */
    public function setValues(array $values): void
    {
        $this->values = $values;
    }

    /**
     * @return array
     */
    public function getValues()
    {
        return $this->values;
    }
}