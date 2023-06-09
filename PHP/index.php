<?php
session_start();
require_once ("objects/database/AllDatabase.php");

$database = new \database\AllDatabase();

require_once ("elements/dice.php");

require_once ("objects/item/Inventory.php");

$inventory = new \item\Inventory($database->getItemDatabase()->getData());

$_SESSION['Inventory'] = serialize($inventory);

header("Location: windows/basic/inventory.php");

