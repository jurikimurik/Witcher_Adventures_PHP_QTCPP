<?php

require_once ("Action.php");

class RewardAction extends Action
{
    private int $money;
    private array $items;

    public function __construct($actionType, $data, $toActionId, $splitter)
    {
        parent::__construct($actionType, $data, $toActionId, $splitter);

        $neededData = $data . explode($splitter);

        $this->money = intval($neededData[1]);
        foreach ($neededData[2].explode("|") as $value)
        {
            if(!empty($value))
                $this->items[] = intval($value);
        }
    }

    /**
     * @return array
     */
    public function getEnemies(): array
    {
        return $this->enemies;
    }

    /**
     * @param array $enemies
     */
    public function setEnemies(array $enemies): void
    {
        $this->enemies = $enemies;
    }

    /**
     * @return mixed
     */
    public function getMoney()
    {
        return $this->money;
    }

    /**
     * @param mixed $money
     */
    public function setMoney($money): void
    {
        $this->money = $money;
    }
}