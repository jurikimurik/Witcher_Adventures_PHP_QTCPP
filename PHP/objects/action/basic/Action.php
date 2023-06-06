<?php

class Action
{
    private int $actionType;
    private string $data;
    private int $toActionId;
    private string $splitter;

    /**
     * @return int
     */
    public function getActionType(): int
    {
        return $this->actionType;
    }

    /**
     * @param int $actionType
     */
    public function setActionType(int $actionType): void
    {
        $this->actionType = $actionType;
    }

    /**
     * @return string
     */
    public function getData(): string
    {
        return $this->data;
    }

    /**
     * @param string $data
     */
    public function setData(string $data): void
    {
        $this->data = $data;
    }

    /**
     * @return int
     */
    public function getToActionId(): int
    {
        return $this->toActionId;
    }

    /**
     * @param int $toActionId
     */
    public function setToActionId(int $toActionId): void
    {
        $this->toActionId = $toActionId;
    }

    /**
     * @return string
     */
    public function getSplitter(): string
    {
        return $this->splitter;
    }

    /**
     * @param string $splitter
     */
    public function setSplitter(string $splitter): void
    {
        $this->splitter = $splitter;
    }



    public function __construct($actionType, $data, $toActionId, $splitter)
    {
        $this->actionType = $actionType;
        $this->data = $data;
        $this->toActionId = $toActionId;
        $this->splitter = $splitter;
    }
}