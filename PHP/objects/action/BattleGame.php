<?php

namespace action;

use character\Character;
use database\basic\CharacterDatabase;
use item\Item;
use player\Player;

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

    }

    public function playerMove(string $PlayerBattleMove) : void
    {

    }

    private function attack(Character &$attacker, Character &$defender) : void
    {

    }

    private function useItem(Character &$user, Item &$item)
    {

    }

    private function defend(Character &$character) : void
    {

    }

    //-----------VISUALS------------------
    public function getVisualBattleEnd() : string
    {
        $visualString = "";
        if($this->player->getAttributes()->getAttributes()[2] >= 0)
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

        foreach ($this->enemies as $enemy)
        {
            /** @var Character $enemy */
            $enemyName = $enemy->getName();
            $enemyId = $enemy->getId();
            $visualString = $visualString . "<button name='PlayerBattleMove' value='Attack:$enemyId'>Atakuj $enemyName!</button> <br>";
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

    public function isEnd(): bool
    {
        if(count($this->enemies) == 0 || $this->player->getAttributes()->getAttributes()[2] <= 0)
            return true;
        else
            return false;
    }
}