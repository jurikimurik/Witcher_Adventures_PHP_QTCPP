<?php

namespace database;

use database\basic\EventDatabase;
use database\basic\CharacterDatabase;
use database\basic\ConsequenceDatabase;
use database\basic\ItemDatabase;

require_once ("DatabaseWorker.php");

class AllDatabase
{
    private EventDatabase $actionDatabase;
    private CharacterDatabase $characterDatabase;
    private ConsequenceDatabase $consequenceDatabase;
    private ItemDatabase $itemDatabase;

    public function __construct()
    {
        $this->loadDatabase();
    }


    /**
     * @return EventDatabase
     */
    public function &getActionDatabase(): EventDatabase
    {
        return $this->actionDatabase;
    }

    /**
     * @param EventDatabase $actionDatabase
     */
    public function setActionDatabase(EventDatabase $actionDatabase): void
    {
        $this->actionDatabase = $actionDatabase;
    }

    /**
     * @return CharacterDatabase
     */
    public function &getCharacterDatabase(): CharacterDatabase
    {
        return $this->characterDatabase;
    }

    /**
     * @param CharacterDatabase $characterDatabase
     */
    public function setCharacterDatabase(CharacterDatabase $characterDatabase): void
    {
        $this->characterDatabase = $characterDatabase;
    }

    /**
     * @return ConsequenceDatabase
     */
    public function &getConsequenceDatabase(): ConsequenceDatabase
    {
        return $this->consequenceDatabase;
    }

    /**
     * @param ConsequenceDatabase $consequenceDatabase
     */
    public function setConsequenceDatabase(ConsequenceDatabase $consequenceDatabase): void
    {
        $this->consequenceDatabase = $consequenceDatabase;
    }

    /**
     * @return ItemDatabase
     */
    public function &getItemDatabase(): ItemDatabase
    {
        return $this->itemDatabase;
    }

    /**
     * @param ItemDatabase $itemDatabase
     */
    public function setItemDatabase(ItemDatabase $itemDatabase): void
    {
        $this->itemDatabase = $itemDatabase;
    }

    private function loadDatabase()
    {
        DatabaseWorker::readDatabase("data.xml", $this);
    }
}