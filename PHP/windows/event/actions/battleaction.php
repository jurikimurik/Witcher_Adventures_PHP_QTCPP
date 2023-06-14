<?php

use action\BattleGame;
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

if(isset($_POST['PlayerBattleMove']))
{
    $_SESSION['PlayerBattleMove'] = $_POST['PlayerBattleMove'];
    unset($_POST['PlayerBattleMove']);
}


if(isset($_POST['BattleEnd'])) {
    $battleGame = unserialize($_SESSION['BattleGame']);
    /** @var BattleGame $battleGame */

    echo $battleGame->getVisualBattleEnd();
    echo $battleGame->getVisualActionsForm();
} else if(isset($_SESSION['BattleInProcess'])) {
    $battleGame = unserialize($_SESSION['BattleGame']);
    /** @var BattleGame $battleGame */

    $battleGame->playerMove($player, $_SESSION['PlayerBattleMove']);
    $battleGame->charactersTurn();

    echo $battleGame->getVisualCharacters();
    echo $battleGame->getVisualActionsForm();
} else {
    $battleGame = new BattleGame($action, $player);
    echo "<html lang='pl'>
    <form action='battleaction.php' method='post'>".
        $battleGame->getVisualTextBlock().
        "<button name='BattleInProcess' value='true'>Walczmy!</button>
    </form>
    </html>";
}

$_SESSION['BattleGame'] = serialize($battleGame);





