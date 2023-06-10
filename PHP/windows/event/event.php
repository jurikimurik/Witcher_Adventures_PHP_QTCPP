<?php

use action\Event;
use database\AllDatabase;

session_start();

require_once ("actions/agilityaction.php");
require_once ("actions/battleaction.php");
require_once ("actions/choiceaction.php");
require_once ("actions/descriptionaction.php");
require_once ("actions/diceaction.php");
require_once ("actions/rewardaction.php");

if(!isset($_SESSION['CurrentEventIndex']))
{
    header("Location: ../../index.php");
}

/** @var AllDatabase $database */
$database = unserialize($_SESSION['Database']);


$event = $database->getActionDatabase()->get($_SESSION['CurrentEventIndex']);
/** @var Event $event */

if(!isset($_SESSION['CurrentActionIndex'])) {}
    $_SESSION['CurrentActionIndex'] = 0;

$action = $event->getAction($_SESSION['CurrentActionIndex']);

$toWindow = 'Location: ../../index.php';

switch ($action->getActionType()) {
    //Description action
    case 1: $toWindow = 'Location: actions/descriptionaction.php'; break;

    //Agility action
    case 2: $toWindow = 'Location: actions/agilityaction.php';  break;

    //Battle action
    case 3: $toWindow = 'Location: actions/battleaction.php';  break;

    //Reward action
    case 4: $toWindow = 'Location: actions/rewardaction.php';  break;

    //Choice action
    case 5: $toWindow = 'Location: actions/choiceaction.php';  break;

    //Dice action
    case 6: $toWindow = 'Location: actions/diceaction.php';  break;
}

header($toWindow);