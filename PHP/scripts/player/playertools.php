<?php

$ROOT = $ROOT = dirname(__FILE__, 3);

use item\Inventory;
use item\Item;
use player\Player;

require_once($ROOT.'/objects/database/basic/ItemDatabase.php');
require_once($ROOT.'/objects/item/Item.php');

function equipNewEquipment(Player &$player, Inventory &$inventory, mixed $armourId, mixed $pantsId, mixed $shoesId, mixed $glovesId): void
{
    if(!empty($armourId))
        $player->setArmour($inventory->get($armourId));

    if(!empty($pantsId))
        $player->setPants($inventory->get($pantsId));

    if(!empty($shoesId))
        $player->setShoes($inventory->get($shoesId));

    if(!empty($glovesId))
        $player->setGloves($inventory->get($glovesId));
}

function getCurrentPlayer() : Player
{
    return unserialize($_SESSION['Player']);
}

function savePlayer(Player $player) : void
{
    $_SESSION['Player'] = serialize($player);
}