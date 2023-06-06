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

        $neededData = explode($splitter, $data);
        $this->difficulty = intval($neededData[1]);
        $this->players = intval($neededData[2]);
        foreach (explode("|", $neededData[3]) as $value)
        {
            $this->enemiesIds[] = intval($value);
        }
        $this->textData = $neededData[4];
    }

    public static function fromAction(Action $action) : DiceAction
    {
        return new DiceAction($action->getActionType(), $action->getData(), $action->getToActionId(), $action->getSplitter());
    }

    /**
     * @return int
     */
    public function getDifficulty(): int
    {
        return $this->difficulty;
    }

    /**
     * @param int $difficulty
     */
    public function setDifficulty(int $difficulty): void
    {
        $this->difficulty = $difficulty;
    }

    /**
     * @return int
     */
    public function getPlayers(): int
    {
        return $this->players;
    }

    /**
     * @param int $players
     */
    public function setPlayers(int $players): void
    {
        $this->players = $players;
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

}