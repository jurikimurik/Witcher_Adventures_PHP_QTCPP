<?php

use action\BattleGame;
use database\AllDatabase;
use player\Player;

session_start();
require_once (realpath(dirname(__FILE__).'/../../../scripts/action/actiontools.php'));

if(isset($_POST['next']))
{
    if($_POST['next'] == 1) {
        $_SESSION['CurrentActionIndex']++;
        var_dump($_SESSION['CurrentActionIndex']);
        unset($_POST['next']);
    } else {
        session_destroy();
        header("Location: ../../../index.php");
    }

}

loadAllActions();

$battleAction = BattleAction::fromAction(getCurrentAction());
$player = getCurrentPlayer();
/** @var Player $player */

if(isset($_POST['BattleInProcess']))
{
    $_SESSION['BattleInProcess'] = $_POST['BattleInProcess'];
    unset($_POST['BattleInProcess']);
}

if(isset($_POST['PlayerBattleMove']))
{
    $_SESSION['PlayerBattleMove'] = $_POST['PlayerBattleMove'];
    unset($_POST['PlayerBattleMove']);
}


if(isset($_POST['BattleEnd'])) {
    $battleGame = unserialize($_SESSION['BattleGame']);
    /** @var BattleGame $battleGame */

    echo $battleGame->getVisualBattleEnd();
    echo $battleGame->getVisualButtonActionsForm();
} else if(isset($_SESSION['BattleInProcess'])) {
    $battleGame = unserialize($_SESSION['BattleGame']);
    /** @var BattleGame $battleGame */

    if(!empty($_SESSION['PlayerBattleMove']))
        $battleGame->playerMove($_SESSION['PlayerBattleMove']);
    $battleGame->charactersTurn();
    $_SESSION['Player'] = serialize($battleGame->getPlayer());

    echo $battleGame->getVisualCharacters();
    echo "<html lang='pl'><form action='battleaction.php' method='post'>";
    echo $battleGame->getVisualButtonActionsForm();
    echo "</form></html>";
} else {
    $battleGame = new BattleGame($battleAction,getCurrentDatabase()->getCharacterDatabase(), $player);

    echo "<html lang='pl'>
    <form action='battleaction.php' method='post'>".
        $battleGame->getVisualTextBlock().
        "<button name='BattleInProcess' value='true'>Walczmy!</button>
    </form>
    </html>";
}

$_SESSION['BattleGame'] = serialize($battleGame);





