<?php

namespace Choice;

use consequence\Consequence;

class Choice
{
    /**
     * @return mixed
     */
    public function getIdToAction()
    {
        return $this->idToAction;
    }

    /**
     * @param mixed $idToAction
     */
    public function setIdToAction($idToAction): void
    {
        $this->idToAction = $idToAction;
    }

    /**
     * @return mixed
     */
    public function getText()
    {
        return $this->text;
    }

    /**
     * @param mixed $text
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