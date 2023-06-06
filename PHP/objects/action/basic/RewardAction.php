<?php

require_once ("Action.php");

class RewardAction extends Action
{
    private $money;
    private $enemies = array();

    public function __construct($actionType, $data, $toActionId, $splitter)
    {
        parent::__construct($actionType, $data, $toActionId, $splitter);
        //TODO: GET DATA FROM ACTION
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