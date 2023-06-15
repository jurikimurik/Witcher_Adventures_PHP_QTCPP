<?php

use action\BattleGame;
use database\AllDatabase;
use player\Player;

session_start();

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

require_once (realpath(dirname(__FILE__).'/../../../objects/database/AllDatabase.php'));
require_once (realpath(dirname(__FILE__).'/../../../objects/action/BattleGame.php'));
require_once (realpath(dirname(__FILE__).'/../../../objects/action/basic/BattleAction.php'));
require_once (realpath(dirname(__FILE__).'/../../../objects/player/Player.php'));
require_once (realpath(dirname(__FILE__).'/../../../objects/item/Inventory.php'));


/** @var AllDatabase $database */
$database = unserialize($_SESSION['Database']);
$event = $database->getActionDatabase()->get($_SESSION['CurrentEventIndex']);
$action = $event->getAction($_SESSION['CurrentActionIndex']);
$battleAction = BattleAction::fromAction($action);
$player = unserialize($_SESSION['Player']);
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
    $battleGame = new BattleGame($battleAction,$database->getCharacterDatabase(), $player);

    echo "<html lang='pl'>
    <form action='battleaction.php' method='post'>".
        $battleGame->getVisualTextBlock().
        "<button name='BattleInProcess' value='true'>Walczmy!</button>
    </form>
    </html>";
}

$_SESSION['BattleGame'] = serialize($battleGame);





