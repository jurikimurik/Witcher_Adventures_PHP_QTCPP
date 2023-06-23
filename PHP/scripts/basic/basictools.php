<?php

use database\AllDatabase;
use JetBrains\PhpStorm\NoReturn;
use player\Player;

#[NoReturn] function startNewGame() : void
{
    if(session_status() == PHP_SESSION_NONE)
        session_start();

    $database = new AllDatabase();
    $_SESSION['Database'] = serialize($database);

    $player = new Player($database->getCharacterDatabase()->get(1));

    $_SESSION['Player'] = serialize($player);

    $_SESSION['CurrentEventIndex'] = 1;
    $_SESSION['CurrentActionIndex'] = 0;

    header("Location: ../event/event.php");
    exit();
}