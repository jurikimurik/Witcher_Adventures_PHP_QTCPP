<?php

namespace database;

use database\basic\ActionDatabase;
use database\basic\CharacterDatabase;
use database\basic\ConsequenceDatabase;
use database\basic\ItemDatabase;

class AllDatabase
{
    private ActionDatabase $actionDatabase;
    private CharacterDatabase $characterDatabase;
    private ConsequenceDatabase $consequenceDatabase;
    private ItemDatabase $itemDatabase;
}