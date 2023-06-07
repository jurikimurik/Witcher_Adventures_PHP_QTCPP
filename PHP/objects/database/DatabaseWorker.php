<?php

namespace database;


use database\basic\CharacterDatabase;
require_once ("basic/CharacterDatabase.php");

use database\basic\ConsequenceDatabase;
require_once ("basic/ConsequenceDatabase.php");

require_once (realpath(dirname(__FILE__).'/../consequence/Consequence.php'));
use consequence\Consequence;

use database\basic\EventDatabase;
require_once ("basic/EventDatabase.php");

use database\basic\ItemDatabase;
require_once ("basic/ItemDatabase.php");

require_once(realpath(dirname(__FILE__) . '/../item/Item.php'));
require_once(realpath(dirname(__FILE__) . '/../item/ItemType.php'));

use item\Item;
use item\ItemType;

require_once (realpath(dirname(__FILE__).'/../special/Buff.php'));

use special\Attributes;
use special\Buff;



class DatabaseWorker
{
    public static function readDatabase(string $filename, AllDatabase &$database)
    {
        $xml = simplexml_load_file("data/".$filename);

        foreach ($xml as $key => $value) {
            switch ($key) {
                case "ITEMS": $database->setItemDatabase(self::readItemDatabase($value)); break;
                case "CONSEQUENCES": $database->setConsequenceDatabase(self::readConsequencesDatabase($value)); break;
                case "CHARACTERS": $database->setCharacterDatabase(self::readCharacterDatabase($value)); break;
                case "EVENTS": $database->setActionDatabase(self::readEventsDatabase($value)); break;
            }
        }
    }

    public static function saveDatabase(string $filename, AllDatabase &$database)
    {

    }

    //--------------------------METHODS FOR READING EACH DATABASE--------------------------

    private static function readItemDatabase(?\SimpleXMLElement $value) : ItemDatabase
    {
        $items = new ItemDatabase();

        foreach ($value->children() as $children => $item)
        {
            $items->add(self::readItem($item));
        }

        return $items;
    }

    private static function readConsequencesDatabase(?\SimpleXMLElement $value) : ConsequenceDatabase
    {
        $consequences = new ConsequenceDatabase();

        foreach ($value->children() as $children => $consequence)
        {
            $consequences->add(self::readConsequence($consequence));
        }

        var_dump($consequences);

        return $consequences;
    }

    private static function readCharacterDatabase(?\SimpleXMLElement $value) : CharacterDatabase
    {
        $characters = new CharacterDatabase();

        foreach ($value->children() as $children => $character)
        {

        }

        return $characters;
    }

    private static function readEventsDatabase(?\SimpleXMLElement $value) : EventDatabase
    {
        $events = new EventDatabase();

        foreach ($value->children() as $children => $event)
        {

        }

        return $events;
    }

    //---------------MORE SPECIALIZED FUNCTIONS FOR READING---------------

    private static function readBuff(?\SimpleXMLElement $buff) : Buff
    {
        $buffName = strip_tags($buff->attributes()['Name']);
        $buffDuration = intval(strip_tags($buff->attributes()['Duration']));

        $buffAttribute = $buff->Attributes;
        $attributesStrArray = explode(",", strip_tags($buffAttribute));

        $attributesIntArray = array();
        foreach ($attributesStrArray as $value)
            $attributesIntArray[] = intval($value);

        return new Buff($buffName, $buffDuration, new Attributes($attributesIntArray));
    }

    private static function readItem(?\SimpleXMLElement $item) : Item
    {
        $attributes = $item->attributes();

        $id = intval($attributes['ID']);
        $name = $attributes['Name'];
        $description = $attributes['Description'];
        $image = $attributes['Image'];
        $money = intval($attributes['Money']);

        $typeName = strip_tags($item->Type['Name']);
        $typeDesc = strip_tags($item->Type->asXml());
        $itemType = new ItemType($typeName, $typeDesc);

        $buffs = array();
        foreach ($item as $key => $buff)
        {
            if($key !== "Buff") {
                continue;
            }
            $buffs[] = self::readBuff($buff);
        }

        return new Item($id,$name,$itemType,$description,$image,$money,$buffs);
    }

    private static function readConsequence(?\SimpleXMLElement $consequence) : Consequence
    {
        $consAttributes = $consequence->attributes();

        $id = intval($consAttributes['ID']);
        $name = $consAttributes['Name'];
        $isOn = (bool) intval(strip_tags($consequence));

        return new Consequence($id, $name, $isOn);
    }
}