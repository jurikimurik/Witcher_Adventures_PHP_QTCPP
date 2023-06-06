<?php

require_once ("Action.php");


class ChoiceAction extends \Action
{
    private string $textData;
    private array $choices;

    public function __construct($actionType, $data, $toActionId, $splitter)
    {
        parent::__construct($actionType, $data, $toActionId, $splitter);

        $neededData = $data.explode($splitter);
        $this->textData = $neededData[1];
        foreach ($neededData[2].explode("|") as $str)
        {
            if(empty($str))
                continue;

            $neededStr = $str.explode("~");
            $toId = intval($neededStr[1]);
            $text = $neededStr[2];
            $consequenceId = intval($neededStr[3]);
            $isOn = intval($neededStr[4]);

            $this->choices[] = new \Choice\Choice($toId, $text, new \consequence\Consequence($consequenceId, "FROM CHOICE", $isOn));
        }
    }

    /**
     * @return mixed
     */
    public function getTextData()
    {
        return $this->textData;
    }

    /**
     * @param mixed $textData
     */
    public function setTextData($textData): void
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