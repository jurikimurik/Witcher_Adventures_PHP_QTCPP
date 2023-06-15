<?php
session_start();
require_once (realpath(dirname(__FILE__).'/../../../scripts/action/actiontools.php'));
use database\AllDatabase;

checkAndLoadNext('next');

loadAllActions();

$rewardAction = RewardAction::fromAction(getCurrentAction());
$itemDatabase = getCurrentDatabase()->getItemDatabase();
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
