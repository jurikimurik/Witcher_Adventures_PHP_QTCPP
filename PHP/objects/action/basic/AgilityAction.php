<?php

require_once ("Action.php");

class AgilityAction extends Action
{
    private $difficulty;
    private $timePerOne;

    public function __construct($actionType, $data, $toActionId, $splitter)
    {
        parent::__construct($actionType, $data, $toActionId, $splitter);
        // TODO: GET DATA FROM ACTION
    }

    /**
     * @return mixed
     */
    public function getTimePerOne()
    {
        return $this->timePerOne;
    }

    /**
     * @param mixed $timePerOne
     */
    public function setTimePerOne($timePerOne): void
    {
        $this->timePerOne = $timePerOne;
    }

    /**
     * @return mixed
     */
    public function getDifficulty()
    {
        return $this->difficulty;
    }

    /**
     * @param mixed $difficulty
     */
    public function setDifficulty($difficulty): void
    {
        $this->difficulty = $difficulty;
    }
}