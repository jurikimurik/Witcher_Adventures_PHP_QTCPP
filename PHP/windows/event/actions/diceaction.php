<?php

use action\DiceGame;
use database\AllDatabase;
use player\Player;

session_start();
require_once (realpath(dirname(__FILE__).'/../../../scripts/actions/actiontools.php'));

checkAndLoadNext('playerWon');

loadAllActions();

loadInventory();

$diceAction = DiceAction::fromAction(getCurrentAction());

echo '<html lang="pl">';

if(!isset($_SESSION['DiceGame'])) {
    $player = unserialize($_SESSION['Player']);
    /** @var Player $player */

    $diceGame = new DiceGame($diceAction, getCurrentDatabase()->getCharacterDatabase(), $player);
    $diceGame->addDice("", 6);
    echo '<form action="diceaction.php" method="post">'.
                $diceGame->getVisualTextBlock().
                '<button name="beginGame">Zacznijmy grę!</button>'.
          '</form>';
} else {
    $diceGame = unserialize($_SESSION['DiceGame']);
    /** @var DiceGame $diceGame */

    $diceGame->rollTheDice();

    echo $diceGame->getVisualAllPlayerDices();
    echo $diceGame->getVisualWinner();

    $player = unserialize($_SESSION['Player']);
    /** @var Player $player */

    if($diceGame->whoWon() === $player->getName())
    {
        echo
        "<form action='diceaction.php' method='post'>
            <fieldset>
            <legend>Wygrałeś!</legend>
            <button name='playerWon' value='true'>O tak! Ruszamy dalej!</button>
            </fieldset>
        </form>";
    } else {
        echo
        "<form action='diceaction.php' method='post'>
            <fieldset>
            <legend>Przegrałeś!</legend>
            <button name='playerWon' value='false'>O nie! Stracilem pieniądze!</button>
            </fieldset>
        </form>";
    }
}

$_SESSION['DiceGame'] = serialize($diceGame);

echo '</html>';
