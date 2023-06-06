<?php

class Action
{
    private $actionType;
    private $data;
    private $toActionId;
    private $splitter;

    public function __construct($actionType, $data, $toActionId, $splitter)
    {
        $this->actionType = $actionType;
        $this->data = $data;
        $this->toActionId = $toActionId;
        $this->splitter = $splitter;
    }
}