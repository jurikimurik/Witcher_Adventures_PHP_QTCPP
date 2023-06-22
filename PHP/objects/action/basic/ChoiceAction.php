<?php

use Choice\Choice;
use consequence\Consequence;

require_once ("Action.php");


class ChoiceAction extends Action
{
    private string $textData;
    private array $choices;

    public function __construct(int $actionType, string $data, int  $toActionId, string $splitter)
    {
        parent::__construct($actionType, $data, $toActionId, $splitter);

        $neededData = explode($splitter, $data);
        $this->textData = $neededData[1];
        foreach (explode("|", $neededData[2]) as $str)
        {
            if(empty($str))
                continue;

            $neededStr = explode("~", $str);
            $toId = intval($neededStr[1]);
            $text = $neededStr[2];
            $consequenceId = intval($neededStr[3]);
            $isOn = intval($neededStr[4]);

            $this->choices[] = new Choice($toId, $text, new Consequence($consequenceId, "FROM CHOICE", $isOn));
        }
    }

    public static function fromAction(Action $action) : ChoiceAction
    {
        return new ChoiceAction($action->getActionType(), $action->getData(), $action->getToActionId(), $action->getSplitter());
    }

    /**
     * @return string
     */
    public function getTextData(): string
    {
        return $this->textData;
    }

    /**
     * @param string $textData
     */
    public function setTextData(string $textData): void
    {
        $this->textData = $textData;
    }

    /**
     * @return array
     */
    public function getChoices(): array
    {
        return $this->choices;
    }

    /**
     * @param array $choices
     */
    public function setChoices(array $choices): void
    {
        $this->choices = $choices;
    }
}