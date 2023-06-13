<?php

namespace action;

use character\Character;
use database\basic\CharacterDatabase;

class DiceGame
{
    private \DiceAction $action;
    private array $allPlayerDices = array();   //ASSOCIATIVE ARRAY

    public function __construct(\DiceAction $action, CharacterDatabase $database)
    {
        $this->action = $action;

        //Getting all names of enemies from database
        foreach ($database as $character)
        {
            /** @var Character $character */
            $this->allPlayerDices[$character->getName()] = array();
        }
    }


    //------------------GAME MECHANICS------------------
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




}