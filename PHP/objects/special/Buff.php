<?php

namespace special;
$ROOT = dirname(__FILE__, 3);
require_once($ROOT.'/objects/special/Attributes.php');

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

        // 0 - MAX HP, 1 - MAX MP, 2 - CURRENT HP, 3 - CURRENT MP, 4 - ATTACK, 5 - DEFENSE, 6 - AGILITY
        for($i = 0; $i < count($newValues); $i++)
        {
            if($i === 2) {

                // ---- ADDING CURRENT HP
                if($newValues[2] + intval($anotherValues[2]) > $newValues[0])
                    $newValues[2] = $newValues[0];
                else
                    $newValues[2] += intval($anotherValues[2]);

            } else if ($i === 3) {

                // ---- ADDING CURRENT MP
                if($newValues[3] + intval($anotherValues[3]) > $newValues[1])
                    $newValues[3] = $newValues[1];
                else
                    $newValues[3] += intval($anotherValues[1]);

            } else {

                // ---- ANOTHER VALUES
                $newValues[$i] += intval($anotherValues[$i]);
            }
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