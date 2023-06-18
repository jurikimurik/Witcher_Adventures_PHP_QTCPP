<?php

namespace consequence;
$ROOT = dirname(__FILE__, 3);
require_once($ROOT.'/objects/basic/DatabaseItem.php');

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