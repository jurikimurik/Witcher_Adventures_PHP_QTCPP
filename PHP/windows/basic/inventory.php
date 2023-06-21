<?php
session_start();
$ROOT = dirname(__FILE__, 3);

use item\Inventory;
use item\Item;

require_once($ROOT.'/objects/item/Inventory.php');
require_once($ROOT.'/objects/item/Item.php');
require_once($ROOT.'/objects/item/ItemType.php');
require_once($ROOT.'/objects/player/Player.php');

require_once($ROOT.'/scripts/tools.php');

if(isset($_POST['backButton']))
{
    $url = getBackURL();
    header("Location: $url");
    exit();
}

$player = getCurrentPlayer();

$inventory = $player->getInventory();
$items = $inventory->getData();

if(isset($_POST['newEquipment']))
{
    equipNewEquipment($player, $inventory, $_POST['armourList'], $_POST['pantsList'], $_POST['shoesList'], $_POST['glovesList']);
    unset($_POST['newEquipment']);
}

if(isset($_POST['itemToUse']))
{
    $item = $inventory->get($_POST['itemToUse']);
    if(!isArmour($item))
    {
        $player->useItemFromInventory($_POST['itemToUse']);
    }
    unset($_POST['itemToUse']);
}

$player->setInventory($inventory);
savePlayer($player);

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
                $descInStr = getBuffStatisticsBlock($buff);
            }

            echo '<fieldset style="display: inline-block">
                    <legend>'.$item->getName().'</legend>'.
                $descInStr
                    .'<button type="submit" name="itemToUse" value="'.$item->getId().'">Użyj</button>
                  </fieldset>';
        }
        ?>
    </fieldset>
<br>
    <fieldset style="display: inline-block">
        <legend>Ekwipunek</legend>
        <table>
            <tr>
                <td>Napiersnik:<label>
                        <select name="armourList">
                                <?php
                                    echo getListOfItemsByType($player, $player->getArmour(), "Armour");
                                ?>
                            </select>
                    </label></td>
            </tr>
            <tr>
                <td>Spodnie:<label>
                        <select name="pantsList">
                                <?php
                                    echo getListOfItemsByType($player, $player->getPants(), "Pants");
                                ?>
                            </select>
                    </label></td>
            </tr>
            <tr>
                <td>Buty:<label>
                        <select name="shoesList">
                                <?php
                                echo getListOfItemsByType($player, $player->getShoes(), "Shoes");
                                ?>
                            </select>
                    </label></td>
            </tr>
            <tr>
                <td>Rękawiczki:<label>
                        <select name="glovesList">
                                <?php
                                echo getListOfItemsByType($player, $player->getGloves(), "Gloves");
                                ?>
                            </select>
                    </label></td>
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
    <button name="backButton">Wróć</button>
</form>
</html>



