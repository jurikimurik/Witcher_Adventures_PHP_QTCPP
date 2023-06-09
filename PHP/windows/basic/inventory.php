<?php
session_start();

use item\Inventory;
use item\Item;
use player\Player;

require_once ("../../objects/item/Inventory.php");
require_once ("../../objects/item/Item.php");
require_once ("../../objects/item/ItemType.php");
require_once ("../../objects/player/Player.php");

require_once ("../../scripts/tools.php");




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
    <fieldset style="display: inline-block">
        <legend>Inwentarz</legend>
        <?php
        foreach ($items as $item) {
            /** @var Item $item */
            $descInStr = '';
            foreach ($item->getBuffs() as $buff)
            {
                $descInStr = '<fieldset style="display: inline-block"> <table>';
                foreach (getBuffStatistics($buff) as $value)
                {
                    $descInStr = $descInStr . '<tr><td>'.$value.'</td></tr>';
                }
                $descInStr = $descInStr . '</table></fieldset>';
            }

            echo '<fieldset style="display: inline-block">
                    <legend>'.$item->getName().'</legend>'.
                $descInStr
                    .'<button type="submit" name="itemToUse" value="'.$item->getName().'">Użyj</button>
                  </fieldset>';
        }
        ?>
    </fieldset>
<br>
    <fieldset style="display: inline-block">
        <legend>Ekwipunek</legend>
        <table>
            <tr>
                <td>Napiersnik:<select name="armourList">
                        <?php
                            echo getListOfItemsByType($player, $player->getArmour(), "Armour");
                        ?>
                    </select></td>
            </tr>
            <tr>
                <td>Spodnie:<select name="pantsList">
                        <?php
                            echo getListOfItemsByType($player, $player->getPants(), "Pants");
                        ?>
                    </select></td>
            </tr>
            <tr>
                <td>Buty:<select name="shoesList">
                        <?php
                        echo getListOfItemsByType($player, $player->getShoes(), "Shoes");
                        ?>
                    </select></td>
            </tr>
            <tr>
                <td>Rękawiczki:<select name="gloves">
                        <?php
                        echo getListOfItemsByType($player, $player->getGloves(), "Gloves");
                        ?>
                    </select></td>
            </tr>
        </table>
        <button type="submit" name="newEquipment">Ubierz nowy stroj</button>
    </fieldset>
<br>
    <fieldset style="display: inline-block">
        <legend>Statystyki</legend>
        <?php
        foreach (getBuffStatistics($player->getCurrentAttributes()) as $value)
        {
            echo $value . '</br>';
        }
        ?>
    </fieldset>
</form>
</html>



