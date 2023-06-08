<?php

if(isset($_POST['New_Game']))
{
    echo 'New Game';
} else if (isset($_POST['Load_Game']))
{
    echo 'Load Game';
} else if (isset($_POST['Options'])) {
    echo 'Options';
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