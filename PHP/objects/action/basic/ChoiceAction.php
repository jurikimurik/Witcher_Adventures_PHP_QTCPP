<?php

require_once ("Action.php");


class ChoiceAction extends \Action
{
    private $textData;
    private $choices = array();

    public function __construct($actionType, $data, $toActionId, $splitter)
    {
        parent::__construct($actionType, $data, $toActionId, $splitter);
        // TODO: GET DATA FROM ACTION
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