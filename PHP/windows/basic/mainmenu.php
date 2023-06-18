<?php

session_start();

$ROOT = dirname(__FILE__, 3);
require_once($ROOT.'/objects/database/AllDatabase.php');
require_once($ROOT.'/objects/player/Player.php');
require_once($ROOT.'/scripts/actions/actiontools.php');


if(isset($_POST['New_Game']))
{
    $database = new \database\AllDatabase();
    $_SESSION['Database'] = serialize($database);

    $player = new \player\Player($database->getCharacterDatabase()->get(1));

    $_SESSION['Player'] = serialize($player);

    $_SESSION['CurrentEventIndex'] = 1;
    $_SESSION['CurrentActionIndex'] = 0;

    header("Location: ../event/event.php");
    exit();

} else if (isset($_POST['Load_Game']))
{
    echo 'Load Game (IN PROGRESS)';
} else if (isset($_POST['Options'])) {
    rememberURLForBack();
    header("Location: options.php");
}

?>


<FORM action = "mainmenu.php" method="POST">
    <fieldset>
        <legend>Wiedżmin: Przygody Kalisto</legend>
        <TABLE>
            <TR>
                <TD><INPUT type="submit" value="Nowa gra" name="New_Game"></TD>
            </TR>
            <TR>
                <TD><INPUT type = "submit" value="Zaladuj gre" name="Load_Game"></TD>
            </TR>
            <TR>
                <TD><INPUT type="submit" value="Opcje" name="Options"></TD>
            </TR>
        </TABLE>
    </fieldset>
</FORM>