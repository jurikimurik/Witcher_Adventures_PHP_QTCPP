<?php

namespace action;

use character\Character;
use database\basic\CharacterDatabase;
use item\Item;
use player\Player;
use special\Attributes;
use special\Buff;

class BattleGame
{
    private array $enemies = array();
    private Player $player;
    private \BattleAction $action;

    public function __construct(\BattleAction $battleAction, CharacterDatabase &$database, Player $player)
    {
        $this->action = $battleAction;
        $this->player = $player;

        foreach ($battleAction->getEnemiesIds() as $id)
        {
            $this->enemies[] = $database->get($id);
        }
    }

    private function checkEnemies() : void
    {
        for($i = 0; $i < count($this->enemies); $i++)
        {
            /** @var Character $enemy */
            $enemy = $this->enemies[$i];

            if($enemy->getAttributes()->getAttributes()[2] <= 0)
            {
                array_splice($this->enemies, $i, 1);
                $i = -1;
            }
        }
    }

    //-----------GAME MECHANICS-----------

    public function charactersTurn() : void
    {
        for ($i = 0; $i <= count($this->enemies); $i++)
        {
            /** @var Character $enemy */
            $enemy = $this->enemies[$i];
            $buff = $enemy->getAttributes();
            $buff->durationDecrease();
            $enemy->setAttributes($buff);

            $this->enemies[$i] = $enemy;

            $this->attack($enemy, $this->player);
        }


    }

    public function playerMove(string $PlayerBattleMove) : void
    {
        $moveData = explode(":", $PlayerBattleMove);

        $actionText = $moveData[0];
        $actionForWho = "";
        if(count($moveData) > 0)
            $actionForWho = $moveData[1];

        $character = "";
        switch ($actionForWho) {
            case "this": $character = $this->player; break;
            default: $character = $this->enemies[intval($actionForWho)];
        }

        switch ($actionText) {
            case "Attack:": $this->attack($this->player, $character); break;
            //case "Defend:"; $this->defend($this->player); break;
            default: var_dump("NIEZROZUMIALA AKCJA!");
        }


        //APPLY EFFECTS
        switch ($actionForWho) {
            case "this": $this->player = $character; break;
            default: $this->enemies[intval($actionForWho)] = $character;
        }

        $buff = $this->player->getAttributes();
        $buff->durationDecrease();
        $this->player->setAttributes($buff);
    }

    private function attack(Character &$attacker, Character &$defender) : void
    {
        $attack = $attacker->getAttributes()->getAttributes()->getValues()[4];
        $defend = $defender->getAttributes()->getAttributes()->getValues()[5];
        $agility = $defender->getAttributes()->getAttributes()->getValues()[6];

        //Agility check
        if(rand(0, 100) <= $agility) {
            // EVADE
            return;
        }

        $damage = (($attack * 2) + rand(0, $attack/10)) - ($defend * 2);

        $buff = $defender->getAttributes();
        $attributes = $buff->getAttributes();

        $array = $attributes->getValues();
        $array[2] = $array[2] - $damage;
        $attributes->setValues($array);

        $buff->setAttributes($attributes);

        $defender->setAttributes($buff);
    }

    /*private function defend(Character &$character) : void
    {
        $buff = new Buff("Defend", 1, new Attributes(0, 0, ));
    }*/

    //-----------VISUALS------------------
    public function getVisualBattleEnd() : string
    {
        $visualString = "";
        if($this->player->getAttributes()->getAttributes()->getValues()[2] >= 0)
        {
            $visualString = $visualString . "Wygrałeś!";
        } else {
            $visualString = $visualString . "Przegrałeś!";
        }
        $visualString = $visualString . "<button name='next'>Koniec bitwy!</button>";
        return $visualString;
    }

    /**
     * @return Player
     */
    public function getPlayer(): Player
    {
        return $this->player;
    }

    public function getVisualButtonActionsForm() : string
    {
        $this->checkEnemies();

        $visualString = "";

        if($this->isEnd())
        {
            return $this->getVisualBattleEnd();
        }

        for ($i = 0; $i < count($this->enemies); $i++)
        {
            /** @var Character $enemy */
            $enemy = $this->enemies[$i];

            $enemyName = $enemy->getName();
            $visualString = $visualString . "<button name='PlayerBattleMove' value='Attack:$i'>Atakuj $enemyName!</button> <br>";
        }
        $visualString = $visualString . "<button name='PlayerBattleMove' value='Defend:this'>Broń się</button> <br>";

        return $visualString;
    }
    public function getVisualCharacters() : string
    {
        $this->checkEnemies();

        $visualString = "";
        foreach ($this->enemies as $enemy)
        {
            /** @var Character $enemy */
            $visualString = $visualString .
                "<fieldset>
                    <legend>".$enemy->getName()."</legend>".
                    "HP:".$enemy->getAttributes()->getAttributes()->getValues()[2].
                "</fieldset>";
        }

        $visualString = $visualString . '<fieldset>
                    <legend>'.$this->player->getName().'</legend>'.
            'HP:'.$this->player->getAttributes()->getAttributes()->getValues()[2].
            '</fieldset>';

        return $visualString;
    }

    public function getVisualTextBlock() : string
    {
        return
            "<fieldset>
                <legend>Wydarzenie</legend>".
            $this->action->getTextData().
            "</fieldset>";
    }

    //--------------------------------------------------

    public function isEnd(): bool
    {
        if(count($this->enemies) == 0 || $this->player->getAttributes()->getAttributes()->getValues()[2] <= 0)
            return true;
        else
            return false;
    }
}