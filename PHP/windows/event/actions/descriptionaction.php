<?php
session_start();

if(isset($_POST['Next']))
{
    $_SESSION['CurrentActionIndex']++;
    var_dump($_SESSION['CurrentActionIndex']);
    unset($_POST['next']);
}

use action\Event;
use database\AllDatabase;

require_once (realpath(dirname(__FILE__).'/../../../objects/database/AllDatabase.php'));
require_once (realpath(dirname(__FILE__).'/../../../objects/action/basic/DescriptionAction.php'));


/** @var AllDatabase $database */
$database = unserialize($_SESSION['Database']);

$event = $database->getActionDatabase()->get($_SESSION['CurrentEventIndex']);

$action = $event->getAction($_SESSION['CurrentActionIndex']);

$descriptionAction = DescriptionAction::fromAction($action);

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
