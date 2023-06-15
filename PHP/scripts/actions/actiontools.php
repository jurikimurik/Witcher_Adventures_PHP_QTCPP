<?php

function checkAndLoadNext($postData) : bool
{
    if(isset($_POST[$postData]))
    {
        $_SESSION['CurrentActionIndex']++;
        unset($_POST[$postData]);
        clearActionData();
        header("Location: ../../windows/event.php");
        return true;
    } else {
        return false;
    }
}

function clearActionData()
{
    //Agility action
    unset($_SESSION['AgilityGame']);
    //Battle action

    //Choice action
    //Description action
    //Dice action
    //Reward action
}

function loadAllActions() : void
{
    require_once (realpath(dirname(__FILE__).'/../../../objects/database/AllDatabase.php'));
    require_once (realpath(dirname(__FILE__).'/../../../objects/action/AgilityGame.php'));
    require_once (realpath(dirname(__FILE__).'/../../../objects/action/BattleGame.php'));
    require_once (realpath(dirname(__FILE__).'/../../../objects/action/DiceGame.php'));
    require_once (realpath(dirname(__FILE__).'/../../../objects/action/basic/AgilityAction.php'));
    require_once (realpath(dirname(__FILE__).'/../../../objects/action/basic/BattleAction.php'));
    require_once (realpath(dirname(__FILE__).'/../../../objects/action/basic/ChoiceAction.php'));
    require_once (realpath(dirname(__FILE__).'/../../../objects/action/basic/DescriptionAction.php'));
    require_once (realpath(dirname(__FILE__).'/../../../objects/action/basic/DiceAction.php'));
    require_once (realpath(dirname(__FILE__).'/../../../objects/action/basic/RewardAction.php'));
    require_once (realpath(dirname(__FILE__).'/../../../objects/action/basic/Choice/Choice.php'));
    require_once (realpath(dirname(__FILE__).'/../../../objects/player/Player.php'));
    require_once (realpath(dirname(__FILE__).'/../../../objects/item/Inventory.php'));
    require_once (realpath(dirname(__FILE__).'/../../../scripts/special/bufftools.php'));
    require_once (realpath(dirname(__FILE__).'/../../../elements/dice.php'));
}

function getCurrentDatabase() : \database\AllDatabase
{
    return unserialize($_SESSION['Database']);
}

function getCurrentEvent() : \action\Event
{
    return getCurrentDatabase()->getActionDatabase()->get($_SESSION['CurrentEventIndex']);
}

function getCurrentAction() : Action
{
    return getCurrentEvent()->getAction($_SESSION['CurrentActionIndex']);
}

function getCurrentPlayer() : \player\Player
{
    return unserialize($_SESSION['Player']);
}