<?php

namespace consequence;

require_once (realpath(dirname(__FILE__).'/../basic/DatabaseItem.php'));

class Consequence extends \DatabaseItem
{
    private bool $isOn;
    public function __construct(int $id, string $name, bool $isOn)
    {
        parent::__construct($id, $name);
        $this->isOn = $isOn;
    }

    /**
     * @return bool
     */
    public function isOn(): bool
    {
        return $this->isOn;
    }

    /**
     * @param bool $isOn
     */
    public function setIsOn(bool $isOn): void
    {
        $this->isOn = $isOn;
    }

}