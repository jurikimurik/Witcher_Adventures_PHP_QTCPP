<?php

namespace action;

class Event
{
    private string $description;
    private array $actions;

    public function __construct(array $actions, string $description = "")
    {
        $this->description = $description;
        $this->actions = $actions;
    }

    public function addAction(\Action $action)
    {
        $action[] = $action;
    }

    public function getAction(int $which) : \Action
    {
        if($which < count($this->actions)) {
            return $this->actions[$which];
        } else {
            return new \Action(0, "", 0, "");
        }
    }

    public function removeAction(int $which)
    {
        if($which >= count($this->actions))
            return;

        array_splice($this->actions, $which, 1);
    }

    /**
     * @return string
     */
    public function getDescription(): string
    {
        return $this->description;
    }

    /**
     * @param string $description
     */
    public function setDescription(string $description): void
    {
        $this->description = $description;
    }

    /**
     * @return array
     */
    public function getActions(): array
    {
        return $this->actions;
    }

    /**
     * @param array $actions
     */
    public function setActions(array $actions): void
    {
        $this->actions = $actions;
    }
}