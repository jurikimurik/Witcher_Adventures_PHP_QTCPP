<?php

session_start();
$ROOT = dirname(__FILE__, 4);
require_once($ROOT.'/scripts/actions/actiontools.php');

use Choice\Choice;

if(isset($_POST['choiceButton']))
{
    $_SESSION['CurrentActionIndex'] = $_POST['choiceButton']-1;
    checkAndLoadNext('choiceButton');
}

loadAllActions();

loadInventory();

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

