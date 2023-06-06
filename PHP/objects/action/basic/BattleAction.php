<?php

require_once ("Action.php");

class BattleAction extends Action
{
    private $textData;
    private $enemiesIds = array();

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
    public function getEnemiesIds(): array
    {
        return $this->enemiesIds;
    }

    /**
     * @param array $enemiesIds
     */
    public function setEnemiesIds(array $enemiesIds): void
    {
        $this->enemiesIds = $enemiesIds;
    }
}