<?php

namespace Choice;

use consequence\Consequence;

class Choice
{
    /**
     * @return mixed
     */
    public function getIdToAction(): mixed
    {
        return $this->idToAction;
    }

    /**
     * @param int $idToAction
     */
    public function setIdToAction(int $idToAction): void
    {
        $this->idToAction = $idToAction;
    }

    /**
     * @return mixed
     */
    public function getText(): mixed
    {
        return $this->text;
    }

    /**
     * @param string $text
     */
    public function setText($text): void
    {
        $this->text = $text;
    }

    /**
     * @return Consequence
     */
    public function getConsequence(): Consequence
    {
        return $this->consequence;
    }

    /**
     * @param Consequence $consequence
     */
    public function setConsequence(Consequence $consequence): void
    {
        $this->consequence = $consequence;
    }
    private int $idToAction;
    private string $text;
    private Consequence $consequence;

    public function __construct($idToAction, $text, Consequence $consequence)
    {
        $this->idToAction = $idToAction;
        $this->text = $text;
        $this->consequence = $consequence;
    }
}