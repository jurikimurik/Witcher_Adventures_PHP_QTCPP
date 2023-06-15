<?php
session_start();
require_once (realpath(dirname(__FILE__).'/../../../scripts/actions/actiontools.php'));
use database\AllDatabase;

checkAndLoadNext('next');

loadAllActions();

$rewardAction = RewardAction::fromAction(getCurrentAction());
$itemDatabase = getCurrentDatabase()->getItemDatabase();
$money = $rewardAction->getMoney();
$itemsID = $rewardAction->getItems();
$player = getCurrentPlayer();
?>

<html lang="pl">
<form action="rewardaction.php" method="post">
    <fieldset>
        <legend>Znalazleś!</legend>
        <?php
        $inventory = $player->getInventory();

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
            if(!isset($_SESSION['RewardCollected']))
                $inventory->add(getCurrentDatabase()->getItemDatabase()->get($itemID));
        }

        $player->setInventory($inventory);
        $_SESSION['Player'] = serialize($player);

        $_SESSION['RewardCollected'] = true;
        ?>
    </fieldset>
    <button type="submit" name="next">Ruszamy dalej!</button>
</form>
</html>
