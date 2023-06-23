<?php

require_once ("Action.php");

class RewardAction extends Action
{
    private int $money;
    private array $items;

    public function __construct(int $actionType,string $data,int $toActionId, string $splitter)
    {
        parent::__construct($actionType, $data, $toActionId, $splitter);

        $neededData = explode($splitter, $data);


        $this->money = intval($neededData[1]);
        foreach (explode("|", $neededData[2]) as $value)
        {
            if(!empty($value))
                $this->items[] = intval($value);
        }
    }

    public static function fromAction(Action $action) : RewardAction
    {
        return new RewardAction($action->getActionType(), $action->getData(), $action->getToActionId(), $action->getSplitter());
    }

    /**
     * @return int
     */
    public function getMoney(): int
    {
        return $this->money;
    }

    /**
     * @param int $money
     */
    public function setMoney(int $money): void
    {
        $this->money = $money;
    }

    /**
     * @return array
     */
    public function getItems(): array
    {
        return $this->items;
    }

    /**
     * @param array $items
     */
    public function setItems(array $items): void
    {
        $this->items = $items;
    }

}