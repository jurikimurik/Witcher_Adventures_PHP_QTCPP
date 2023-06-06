<?php

namespace database;

use database\basic\EventDatabase;
use database\basic\CharacterDatabase;
use database\basic\ConsequenceDatabase;
use database\basic\ItemDatabase;

class AllDatabase
{
    private EventDatabase $actionDatabase;
    private CharacterDatabase $characterDatabase;
    private ConsequenceDatabase $consequenceDatabase;
    private ItemDatabase $itemDatabase;
}