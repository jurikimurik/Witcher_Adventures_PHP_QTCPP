<?php

use action\AgilityGame;
use database\AllDatabase;

session_start();
$ROOT = dirname(__FILE__, 4);
require_once($ROOT.'/scripts/actions/actiontools.php');
checkAndLoadNext('next');
loadAllActions();

$agilityAction = AgilityAction::fromAction(getCurrentAction());

if(!isset($_SESSION['AgilityGame'])) {
    $agilityGame = new AgilityGame($agilityAction);
} else {
    $agilityGame = unserialize($_SESSION['AgilityGame']);

    if(isset($_POST['answerButton']))
    {
        $playerAnswer = $_POST['answerButton'];
    } else {
        $playerAnswer = "";
    }
        unset($_POST['answerButton']);

        $agilityGame->checkAnswer($playerAnswer);

        if($agilityGame->isOver()) {
            echo "<form action='agilityaction.php' method='post'>";
            if($agilityGame->isWin()) {
                echo "<fieldset>
                        <legend>Udało ci się w porę wywinąć!</legend>
                        <button name='next'>Ruszamy dalej!</button>
                      </fieldset>";
            } else {
                echo "<fieldset>
                        <legend>Niestety wywaliłeś się!</legend>
                        <button name='next'>Oj nie dobrze...</button>
                      </fieldset>";
            }
            unset($agilityGame);
            echo "</form>";
    }
}

?>

<html lang="pl">
<head>
    <meta http-equiv="refresh" content="<?php echo $agilityAction->getTimePerOne()?>;URL='<?php echo $_SERVER['PHP_SELF']?>'">
</head>
<form action="agilityaction.php" method="post">
    <?php
    if(isset($agilityGame)) {
        echo $agilityGame->getRiddleBlock();
    }
    ?>
</form>

<?php
if(isset($agilityGame)) {
    $_SESSION['AgilityGame'] = serialize($agilityGame);
}
?>

</html>
