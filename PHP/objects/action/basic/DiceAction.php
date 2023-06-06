<?php

require_once ("Action.php");

class DiceAction extends Action
{
    private int $difficulty;
    private int $players;
    private array $enemiesIds;
    private string $textData;

    public function __construct($actionType, $data, $toActionId, $splitter)
    {
        parent::__construct($actionType, $data, $toActionId, $splitter);

        $neededData = $data.explode($splitter);
        $this->difficulty = intval($neededData[1]);
        $this->players = intval($neededData[2]);
        foreach ($neededData[3].explode("|") as $value)
        {
            $this->enemiesIds[] = intval($value);
        }
        $this->textData = $neededData[4];
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

    /**
     * @return mixed
     */
    public function getPlayers()
    {
        return $this->players;
    }

    /**
     * @param mixed $players
     */
    public function setPlayers($players): void
    {
        $this->players = $players;
    }

    /**
     * @return mixed
     */
    public function getEnemies()
    {
        return $this->enemies;
    }

    /**
     * @param mixed $enemies
     */
    public function setEnemies($enemies): void
    {
        $this->enemies = $enemies;
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
}