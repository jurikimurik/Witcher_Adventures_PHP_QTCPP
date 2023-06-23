<?php

require_once ("Action.php");

class BattleAction extends Action
{
    private string $textData;
    private array $enemiesIds;

    public function __construct(int $actionType, string $data, int $toActionId, string $splitter)
    {
        parent::__construct($actionType, $data, $toActionId, $splitter);

        $neededData = explode($splitter, $data);

        $this->textData = $neededData[1];
        foreach (explode("|", $neededData[2]) as $value)
        {
            if(!empty($value))
                $this->enemiesIds[] = intval($value);
        }
    }

    public static function fromAction(Action $action) : BattleAction
    {
        return new BattleAction($action->getActionType(), $action->getData(), $action->getToActionId(), $action->getSplitter());
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