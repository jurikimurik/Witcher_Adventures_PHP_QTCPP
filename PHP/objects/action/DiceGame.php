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
    public function addDice(string $playerName = "")
    {
        if(isset($playerName))
        {
            // GIVE DICE ONLY FOR HIM
            $this->allPlayerDices[$playerName][] = 3;
        } else {
            // GIVE DICE TO EVERYBODY
            foreach ($this->allPlayerDices as $name => $array)
            {
                $this->allPlayerDices[$name][] = 3;
            }
        }
    }
    public function removeDice(string $playerName = "")
    {
        if(isset($playerName))
        {
            // REMOVE DICE ONLY FOR HIM
            array_splice($this->allPlayerDices[$playerName],count($this->allPlayerDices[$playerName])-1,1);
        } else {
            // REMOVE DICE TO EVERYBODY
            foreach ($this->allPlayerDices as $name => $array)
            {
                array_splice($this->allPlayerDices[$name],count($this->allPlayerDices[$name])-1,1);
            }
        }
    }
    public function rollTheDice(string $playerName = "")
    {
        if(isset($playerName))
        {
            // ROLL THE DICE FOR SPECIFIED PLAYER
            $allDices = array();
            $playerDices = $this->allPlayerDices[$playerName];
            for ($i = 0; $i < count($playerDices); $i++)
            {
                $allDices[$i] = rand(1, 6);
            }
            $this->allPlayerDices[$playerName] = $allDices;
        } else {
            // ROLL FOR EVERYBODY
            foreach ($this->allPlayerDices as $name => $diceArray)
            {
                $allDices = array();
                $playerDices = $this->allPlayerDices[$name];
                for ($i = 0; $i < count($playerDices); $i++)
                {
                    $allDices[$i] = rand(1, 6);
                }
                $this->allPlayerDices[$name] = $allDices;
            }
        }
    }



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