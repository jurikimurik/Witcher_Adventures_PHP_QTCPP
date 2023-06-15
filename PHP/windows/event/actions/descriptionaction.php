<?php
session_start();
require_once (realpath(dirname(__FILE__).'/../../../scripts/action/actiontools.php'));

checkAndLoadNext('Next');

use action\Event;
use database\AllDatabase;

loadAllActions();

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
