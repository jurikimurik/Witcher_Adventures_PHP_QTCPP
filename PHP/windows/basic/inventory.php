<?php
session_start();

use item\Inventory;
use player\Player;

require_once ("../../objects/item/Inventory.php");
require_once ("../../objects/item/Item.php");
require_once ("../../objects/item/ItemType.php");
require_once ("../../objects/player/Player.php");


if(isset($_POST['itemToUse']))
{
    echo $_POST['itemToUse'];
    unset($_POST['itemToUse']);
}

if(isset($_SESSION['Player']))
{
    $player = unserialize($_SESSION['Player']);
    /** @var Player $player */

    $inventory = $player->getInventory();

    $items = $inventory->getData();
}

?>

<html lang="pl">
<form action="inventory.php" method="post">
    <fieldset>
        <legend>Inwentarz</legend>
        <?php
        foreach ($items as $item) {
            /** @var \item\Item $item */
            echo '<input type = "submit" value="'.$item->getName().'" name="itemToUse">';
        }
        ?>
    </fieldset>
    <fieldset>
        <legend>Ekwipunek</legend>
        <table>
            <tr>
                <td>Napiersnik:</td>
            </tr>
            <tr>
                <td>Spodnie:</td>
            </tr>
            <tr>
                <td>Buty:</td>
            </tr>
            <tr>
                <td>Rękawiczki:</td>
            </tr>
        </table>
    </fieldset>
    <fieldset>
        <legend>Statystyki</legend>
    </fieldset>
</form>
</html>



