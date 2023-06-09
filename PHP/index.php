<?php
session_start();
require_once ("objects/database/AllDatabase.php");

$database = new \database\AllDatabase();

require_once ("elements/dice.php");

require_once ("objects/item/Inventory.php");

require_once ("objects/player/Player.php");

$inventory = new \item\Inventory($database->getItemDatabase()->getData());

$player = new \player\Player($database->getCharacterDatabase()->get(1),$inventory);

$player->setInventory($inventory);

$_SESSION['Player'] = serialize($player);

header("Location: windows/basic/inventory.php");

