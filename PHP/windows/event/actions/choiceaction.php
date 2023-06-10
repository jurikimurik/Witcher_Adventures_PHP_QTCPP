<?php

session_start();

use Choice\Choice;
use database\AllDatabase;

if(isset($_POST['choiceButton']))
    echo $_POST['choiceButton'];

if(isset($_POST['next']))
{
    $_SESSION['CurrentActionIndex']++;
    var_dump($_SESSION['CurrentActionIndex']);
    unset($_POST['next']);
}

require_once (realpath(dirname(__FILE__).'/../../../objects/database/AllDatabase.php'));
require_once (realpath(dirname(__FILE__).'/../../../objects/action/basic/Choice/Choice.php'));
require_once (realpath(dirname(__FILE__).'/../../../objects/action/basic/ChoiceAction.php'));
require_once (realpath(dirname(__FILE__).'/../../../scripts/special/bufftools.php'));

/** @var AllDatabase $database */
$database = unserialize($_SESSION['Database']);
$itemDatabase = $database->getItemDatabase();

$event = $database->getActionDatabase()->get($_SESSION['CurrentEventIndex']);

$action = $event->getAction($_SESSION['CurrentActionIndex']);

$choiceAction = ChoiceAction::fromAction($action);

$text = $choiceAction->getTextData();
$choices = $choiceAction->getChoices();

?>

<html lang="pl">
<form action="choiceaction.php" method="post">
    <fieldset>
        <legend>Wydarzenie</legend>
        <?php
        echo $text;
        ?>
    </fieldset>
    <fieldset>
        <table>
            <?php
            foreach ($choices as $choice)
            {
                /** @var Choice $choice */
                echo '<tr>
                           <td>
                           <button name="choiceButton" value="'.$choice->getIdToAction().'">'.$choice->getText().'</button>
                           </td>
                      </tr>';
            }
            ?>
        </table>
    </fieldset>
</form>
</html>

