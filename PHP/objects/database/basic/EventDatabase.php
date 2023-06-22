<?php

namespace database\basic;

use action\Event;

class EventDatabase
{
    private array $data = array();

    public function add(Event $event): bool
    {
        if(!in_array($event,$this->data,true)) {
            $this->data[] = $event;
            return true;
        } else {
            return false;
        }
    }

    public function remove(int $which): void
    {
        if($which < count($this->data))
            array_splice($this->data,$which,1);
    }

    public function removeById(int $id): void
    {
        for($i = 0; $i < count($this->data); $i++)
        {
            /** @var Event $event */
            $event = $this->data[$i];
                if($event->getId() === $id)
                {
                    $this->remove($i);
                }
        }
    }

    public function update(Event $event): void
    {
        $this->removeById($event->getId());
        $this->add($event);
    }

    public function get(int $id): Event
    {
        foreach ($this->data as $event)
        {
            /** @var Event $event */
            if($event->getId() === $id)
                return $event;
        }

        return new Event(-1, "", array(), "");
    }


    /**
     * @return array
     */
    public function getData(): array
    {
        return $this->data;
    }

    /**
     * @param array $data
     */
    public function setData(array $data): void
    {
        $this->data = $data;
    }
}