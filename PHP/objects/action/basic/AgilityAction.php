<?php

require_once ("Action.php");

class AgilityAction extends Action
{
    private int $difficulty;
    private int $timePerOne;

    public function __construct(int $actionType, string $data, int $toActionId, string $splitter)
    {
        parent::__construct($actionType, $data, $toActionId, $splitter);
        $neededData = explode($splitter, $data);

        $this->difficulty = intval($neededData[1]);
        $this->timePerOne = intval($neededData[2]);
    }

    public static function fromAction(Action $action) : AgilityAction
    {
        return new AgilityAction($action->getActionType(), $action->getData(), $action->getToActionId(), $action->getSplitter());
    }

    /**
     * @return int
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
     * @return int
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