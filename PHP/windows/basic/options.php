<?php
session_start();
$ROOT = dirname(__FILE__, 3);
require_once($ROOT.'/scripts/actions/actiontools.php');

if(isset($_POST['LoadDatabase']))
{
    echo 'Load Database (IN PROGRESS)';
} else if (isset($_POST['Back'])) {
    $BackURL = getBackURL();
    header("Location: $BackURL");
    exit();
}

?>

<FORM action="options.php" method="post">
    <fieldset>
        <LEGEND>Opcje</LEGEND>
        <table>
            <tr>
                <td><input type = "submit" value="Zaladuj swoja baze danych" name="LoadDatabase"></td>
            </tr>
            <tr>
                <td>Glosnosc muzyki:</td>
                <td>
                    <div class="slidecontainer">
                        <label>
                            <input type="range" min="1" max="100" value="100" class="slider" name="musicVolume">
                        </label>
                    </div>
                </td>
            </tr>
            <tr>
                <td>Glosnosc dzwiekow:</td>
                <td>
                    <div class="slidecontainter">
                        <label>
                            <input type="range" min="1" max="100" value="100" class="slider" name="soundsVolume">
                        </label>
                    </div>
                </td>
            </tr>
            <tr>
                <td><input type="submit" value="Wroc" name="Back"></td>
            </tr>
        </table>
    </fieldset>
</FORM>
