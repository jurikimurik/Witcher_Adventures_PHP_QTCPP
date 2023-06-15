<?php

namespace special;

require_once (realpath(dirname(__FILE__).'/../special/Attributes.php'));

class Buff
{
    private string $name;
    private int $duration;
    private Attributes $attributes;

    public function __construct($name, $duration, Attributes $attributes)
    {
        $this->name = $name;
        $this->duration = $duration;
        $this->attributes = $attributes;
    }

    public function durationDecrease(int $count = 1): void
    {
        if($this->duration >= 1)
        $this->duration -= $count;
    }

    //Sums up two buffs, but NOT their DURATION!!!
    public function sumBuffAttributes(Buff $another): void
    {
        $newValues = $this->getAttributes()->getValues();
        $anotherValues = $another->getAttributes()->getValues();

        //FROM 1, BECAUSE 0 IS DURATION
        for($i = 1; $i < count($newValues); $i++)
        {
            $newValues[$i] += intval($anotherValues[$i]);
        }

        $this->setAttributes(new Attributes($newValues));
    }

    /**
     * @return string
     */
    public function getName(): string
    {
        return $this->name;
    }

    /**
     * @param string $name
     */
    public function setName(string $name): void
    {
        $this->name = $name;
    }

    /**
     * @return int
     */
    public function getDuration(): int
    {
        return $this->duration;
    }

    /**
     * @param int $duration
     */
    public function setDuration(int $duration): void
    {
        $this->duration = $duration;
    }

    /**
     * @return Attributes
     */
    public function getAttributes(): Attributes
    {
        return $this->attributes;
    }

    /**
     * @param Attributes $attributes
     */
    public function setAttributes(Attributes $attributes): void
    {
        $this->attributes = $attributes;
    }

    public static function getStatisticsText(): array
    {
        return array("Długość: ", "Max. HP: ", "Max. MP: ", "Obecne HP: ",
            "Obecne MP: ", "Atak: ", "Obrona: ", "Zrecznosc: ");
    }
}