<?php

session_start();
require_once (realpath(dirname(__FILE__).'/../../../scripts/action/actiontools.php'));

use Choice\Choice;
use database\AllDatabase;

checkAndLoadNext('next');

loadAllActions();

$choiceAction = ChoiceAction::fromAction(getCurrentAction());
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

