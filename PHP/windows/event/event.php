<?php

use action\Event;
use database\AllDatabase;

$ROOT = dirname(__FILE__, 3);
require_once($ROOT.'/objects/database/AllDatabase.php');


session_start();

if(!isset($_SESSION['CurrentEventIndex']))
{
    header("Location: ../../index.php");
    exit();
}

/** @var AllDatabase $database */
$database = unserialize($_SESSION['Database']);

$event = $database->getActionDatabase()->get($_SESSION['CurrentEventIndex']);
    if($event->getId() == -1)
    {
        echo "Wygrałeś!";
        header("../../index.php");
        exit();
    }

if(!isset($_SESSION['CurrentActionIndex']))
{
    $_SESSION['CurrentActionIndex'] = 0;
}


$action = $event->getAction($_SESSION['CurrentActionIndex']);
    if($action->getActionType() == 0)
    {
        $_SESSION['CurrentEventIndex']++;
        header('Location: event.php');
        exit();
    }

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
exit();