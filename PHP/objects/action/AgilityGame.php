<?php

namespace action;

use AgilityAction;

class AgilityGame
{
    public static array $answers = array("Góra", "Dół", "Lewo", "Prawo", "Zaczep się", "Skacz", "Sprintuj","Wyskocz");
    private int $difficulty;
    private int $timePerOne;
    private int $allTurns = 0;
    private int $maxPoints = 0;
    private int $turn = 0;
    private int $points = 0;
    private string $answer = "";

    public function __construct(AgilityAction &$action)
    {
        $this->difficulty = $action->getDifficulty();
        $this->timePerOne = $action->getTimePerOne();
        $this->startNewGame();
    }

    public function checkAnswer(string $playerAnswer) : void
    {
        if($this->isOver())
            return;

        $this->turn++;
        if($playerAnswer == $this->answer)
            $this->points++;
    }

    public function isOver() : bool
    {
        if($this->turn >= $this->allTurns)
            return true;
        else
            return false;
    }

    public function isWin() : bool
    {
        if($this->points >= $this->maxPoints * 0.75) {
            return true;
        } else {
            return false;
        }
    }
    //---------------------------------------------
    //NEW WORD BEING GENERATED WHEN NEW BLOCK GENERATED!
    public function getRiddleBlock() : string
    {
        $workAnswers = AgilityGame::$answers;
        $index = rand(0, count($workAnswers)-1);
        $this->answer = $workAnswers[$index];
        array_splice($workAnswers, $index, 1);


        $answerButtonIndex = rand(0, $this->difficulty-1);
        $block = '<fieldset><legend>Klikaj '.$this->answer.'!</legend>';
        for($i = 0; $i < $this->difficulty && count($workAnswers) > 0; $i++)
        {
            $index = rand(0, count($workAnswers)-1);
            $randWord = $workAnswers[$index];
            array_splice($workAnswers, $index, 1);

            if($i == $answerButtonIndex)
                $block = $block . '<button name="answerButton" value="'.$this->answer.'">'.$this->answer.'</button>';
            else
                $block = $block . '<button name="answerButton" value="'.$randWord.'">'.$randWord.'</button>';

            $x = 3;
            while($x-- > 0)
                $block = $block . '&nbsp;';
        }
        return $block . '</fieldset>';
    }
    //---------------------------------------------
    private function startNewGame() : void
    {
        $this->allTurns = $this->difficulty * 3;
        $this->maxPoints = $this->allTurns;
    }

    /**
     * @return int
     */
    public function getTimePerOne(): int
    {
        return $this->timePerOne;
    }





}