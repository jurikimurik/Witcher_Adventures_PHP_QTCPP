<?php
session_start();
use database\AllDatabase;

if(isset($_POST['next']))
{
    $_SESSION['CurrentActionIndex']++;
    var_dump($_SESSION['CurrentActionIndex']);
    unset($_POST['next']);
}

require_once (realpath(dirname(__FILE__).'/../../../objects/database/AllDatabase.php'));
require_once (realpath(dirname(__FILE__).'/../../../objects/action/basic/RewardAction.php'));
require_once (realpath(dirname(__FILE__).'/../../../scripts/special/bufftools.php'));

/** @var AllDatabase $database */
$database = unserialize($_SESSION['Database']);
$itemDatabase = $database->getItemDatabase();

$event = $database->getActionDatabase()->get($_SESSION['CurrentEventIndex']);

$action = $event->getAction($_SESSION['CurrentActionIndex']);

$rewardAction = RewardAction::fromAction($action);

$money = $rewardAction->getMoney();
$itemsID = $rewardAction->getItems();

?>

<html lang="pl">
<form action="rewardaction.php" method="post">
    <fieldset>
        <legend>Znalazleś!</legend>
        <?php
        if($money > 0)
            echo "Pieniądze: " . $money;
        foreach ($itemsID as $itemID)
        {
            $item = $itemDatabase->get($itemID);
            $descInStr = '';
            foreach ($item->getBuffs() as $buff)
            {
                $descInStr = getBuffStatisticsBlock($buff);
            }

            echo '<fieldset style="display: inline-block">
                    <legend>'.$item->getName().'</legend>'.
                $descInStr.'</fieldset>';
        }
        ?>
    </fieldset>
    <button type="submit" name="next">Ruszamy dalej!</button>
</form>
</html>
