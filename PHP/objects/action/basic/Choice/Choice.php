<?php

namespace Choice;

use consequence\Consequence;

class Choice
{
    private $idToAction;
    private $text;
    private Consequence $consequence;

    public function __construct($idToAction, $text, Consequence $consequence)
    {
        $this->idToAction = $idToAction;
        $this->text = $text;
        $this->consequence = $consequence;
    }
}