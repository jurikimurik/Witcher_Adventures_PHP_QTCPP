<?php

require_once ("Action.php");

class BattleAction extends Action
{
    private string $textData;
    private array $enemiesIds;

    public function __construct($actionType, $data, $toActionId, $splitter)
    {
        parent::__construct($actionType, $data, $toActionId, $splitter);

        $neededData = $data.explode($splitter);

        $this->textData = $neededData[1];
        foreach ($neededData[2].explode("|") as $value)
        {
            if(!empty($value))
                $this->enemiesIds[] = intval($value);
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