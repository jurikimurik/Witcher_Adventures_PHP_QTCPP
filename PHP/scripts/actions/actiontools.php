<?php
function checkAndLoadNext($postData) : bool
{
    if(isset($_POST[$postData]))
    {
        $_SESSION['CurrentActionIndex']++;
        unset($_POST[$postData]);
        clearActionData();
        header("Location: ../../../windows/event/event.php");
        return true;
    } else {
        return false;
    }
}

function clearActionData() : void
{
    //Agility action
    unset($_SESSION['AgilityGame']);

    //Battle action
    unset($_SESSION['BattleInProcess']);
    unset($_SESSION['PlayerBattleMove']);
    unset($_SESSION['BattleGame']);
    //Choice action
    //---NONE---

    //Description action
    //---NONE---

    //Dice action
    unset($_SESSION['DiceGame']);

    //Reward action
    unset($_SESSION['RewardCollected']);
}

function loadAllActions() : void
{
    $ROOT = $ROOT = dirname(__FILE__, 3);
    require_once($ROOT.'/objects/database/AllDatabase.php');
    require_once($ROOT.'/objects/action/AgilityGame.php');
    require_once($ROOT.'/objects/action/BattleGame.php');
    require_once($ROOT.'/objects/action/DiceGame.php');
    require_once($ROOT.'/objects/action/basic/AgilityAction.php');
    require_once($ROOT.'/objects/action/basic/BattleAction.php');
    require_once($ROOT.'/objects/action/basic/ChoiceAction.php');
    require_once($ROOT.'/objects/action/basic/DescriptionAction.php');
    require_once($ROOT.'/objects/action/basic/DiceAction.php');
    require_once($ROOT.'/objects/action/basic/RewardAction.php');
    require_once($ROOT.'/objects/action/basic/Choice/Choice.php');
    require_once($ROOT.'/objects/player/Player.php');
    require_once($ROOT.'/objects/item/Inventory.php');
    require_once($ROOT.'/scripts/special/bufftools.php');
    require_once($ROOT.'/elements/dice.php');
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

function rememberURLForBack() : void
{
    $_SESSION['BackURL'] = getCurrentURL();
}

function getBackURL() : string
{
    if(isset($_SESSION['BackURL']))
        return $_SESSION['BackURL'];
    else {
        return getCurrentURL();
    }

}

function getCurrentURL() : string
{
    if(isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] === 'on')
        $url = "https://";
    else
        $url = "http://";
    // Append the host(domain name, ip) to the URL.
    $url.= $_SERVER['HTTP_HOST'];

    // Append the requested resource location to the URL
    $url.= $_SERVER['REQUEST_URI'];

    return $url;
}

function loadInventory() : void
{
    rememberURLForBack();
    $inventoryButton = getVisualInventoryButton();
    echo "<form method='post'>$inventoryButton</form>";
    if(isset($_POST['openInventory']))
    {
        $path = '../../basic/inventory.php';
        header("Location: $path");
    }
}

function getVisualInventoryButton() : string
{
    $value = getCurrentURL();

    return "<fieldset>
<legend>Inventarz</legend>
<button name = 'openInventory' value='$value'>.Otwórz</button>
</fieldset>";

}