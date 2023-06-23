<?php
session_start();
$ROOT = dirname(__FILE__, 4);
require_once($ROOT.'/scripts/actions/actiontools.php');

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
            if($item->getId() <= -1)
                continue;

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
