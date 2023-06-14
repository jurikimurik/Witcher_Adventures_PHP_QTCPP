<?php

namespace action;

use character\Character;
use player\Player;

class BattleGame
{
    private array $enemies = array();

    //-----------GAME MECHANICS-----------

    public function charactersTurn() : void
    {

    }

    public function playerMove(Player &$player, string $PlayerBattleMove) : void
    {

    }

    private function attack(Character &$attacker, Character &$defender) : void
    {

    }

    private function defend(Character &$character) : void
    {

    }

    //-----------VISUALS------------------
    public function getVisualBattleEnd() : string
    {
    }

    public function getVisualActionsForm() : string
    {
    }
    public function getVisualCharacters() : string
    {
    }

    public function getVisualTextBlock() : string
    {
    }
}