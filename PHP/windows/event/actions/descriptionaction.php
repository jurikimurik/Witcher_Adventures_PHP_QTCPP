<?php
session_start();
$ROOT = dirname(__FILE__, 4);
require_once($ROOT.'/scripts/actions/actiontools.php');

checkAndLoadNext('Next');

loadAllActions();

loadInventory();

$descriptionAction = DescriptionAction::fromAction(getCurrentAction());
$text = $descriptionAction->getTextData();
$music = $descriptionAction->getMusic();
$image = $descriptionAction->getImageName();
?>

<html lang="pl">
<form action="descriptionaction.php" method="post">
    <fieldset>
        <legend>Wydarzenie</legend>
        <?php
        echo $text;
        ?>
    </fieldset>
    <button type="submit" name="Next">Dalej...</button>
</form>
</html>
