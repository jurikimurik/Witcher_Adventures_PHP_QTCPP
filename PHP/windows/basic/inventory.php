<?php
session_start();

use item\Inventory;

require_once ("../../objects/item/Inventory.php");
require_once ("../../objects/item/Item.php");
require_once ("../../objects/item/ItemType.php");

if(isset($_POST['itemToUse']))
{
    echo $_POST['itemToUse'];
    unset($_POST['itemToUse']);
}

if(isset($_SESSION['Inventory']))
{
    $inventory = unserialize($_SESSION['Inventory']);
    /** @var Inventory $inventory */

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
    </fieldset>
    <fieldset>
        <legend>Statystyki</legend>
    </fieldset>
</form>
</html>



