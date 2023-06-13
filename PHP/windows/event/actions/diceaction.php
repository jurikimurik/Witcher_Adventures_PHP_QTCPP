<?php

use action\DiceGame;
use database\AllDatabase;
use player\Player;

session_start();

if(isset($_POST['next']))
{
    $_SESSION['CurrentActionIndex']++;
    var_dump($_SESSION['CurrentActionIndex']);
    unset($_POST['next']);
}

require_once (realpath(dirname(__FILE__).'/../../../objects/database/AllDatabase.php'));
require_once (realpath(dirname(__FILE__).'/../../../objects/action/DiceGame.php'));
require_once (realpath(dirname(__FILE__).'/../../../objects/action/basic/DiceAction.php'));

/** @var AllDatabase $database */
$database = unserialize($_SESSION['Database']);
$event = $database->getActionDatabase()->get($_SESSION['CurrentEventIndex']);
$action = $event->getAction($_SESSION['CurrentActionIndex']);
$diceAction = DiceAction::fromAction($action);

echo '<html lang="pl">';

if(!isset($_SESSION['DiceGame'])) {
    $diceGame = new DiceGame($diceAction, $database->getCharacterDatabase(), unserialize($_SESSION['Player']));
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
