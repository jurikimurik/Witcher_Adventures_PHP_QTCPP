<?php

namespace consequence;

class Consequence extends \DatabaseItem
{
    private $isOn;
    public function __construct($id, $name, $isOn)
    {
        parent::__construct($id, $name);
        $this->isOn = $isOn;
    }

    /**
     * @return mixed
     */
    public function getIsOn()
    {
        return $this->isOn;
    }
}