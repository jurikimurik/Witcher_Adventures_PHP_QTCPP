<?php

namespace action;

use character\Character;
use database\basic\CharacterDatabase;
use player\Player;

class DiceGame
{
    private \DiceAction $action;
    private array $allPlayerDices = array();   //ASSOCIATIVE ARRAY

    public function __construct(\DiceAction $action, CharacterDatabase $database, Player $player)
    {
        $this->action = $action;

        //Getting name of player from provided object
        $this->allPlayerDices[$player->getName()] = array();

        //Getting all names of enemies from database
        foreach ($database as $character)
        {
            /** @var Character $character */
            $this->allPlayerDices[$character->getName()] = array();
        }
    }


    //------------------GAME MECHANICS------------------

    //------------------VISUALS-------------------------
    public function getVisualTextBlock() : string
    {
        $textData = $this->action->getTextData();
        return "<fieldset>
                    <legend>
                    Wydarzenie
                    </legend>
                    $textData
                </fieldset>";
    }

    public function getVisualAllPlayerDices() : string
    {
        $visualString = "";
        foreach ($this->allPlayerDices as $name => $array)
        {
            $playerDiceBlock = "";
            $playerDiceBlock = $playerDiceBlock . "<fieldset>
                                <legend>$name</legend>";
            foreach ($array as $diceNumber)
            {
                $playerDiceBlock = $playerDiceBlock . "|$diceNumber|";
            }
            $playerDiceBlock = $playerDiceBlock . "</fieldset>";
            $visualString = $visualString . $playerDiceBlock;
        }
        return $visualString;
    }


}