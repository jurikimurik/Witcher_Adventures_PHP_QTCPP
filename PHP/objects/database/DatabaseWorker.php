<?php

namespace database;




use database\basic\CharacterDatabase;
$ROOT = dirname(__FILE__, 3);
require_once($ROOT.'/objects/database/basic/CharacterDatabase.php');
require_once($ROOT.'/objects/character/Character.php');
use character\Character;

use database\basic\ConsequenceDatabase;
require_once($ROOT.'/objects/database/basic/ConsequenceDatabase.php');

require_once($ROOT.'/objects/consequence/Consequence.php');
use consequence\Consequence;

use database\basic\EventDatabase;
require_once($ROOT.'/objects/database/basic/EventDatabase.php');

use action\Event;
require_once($ROOT.'/objects/action/basic/Action.php');
require_once($ROOT.'/objects/action/Event.php');


use database\basic\ItemDatabase;
require_once($ROOT.'/objects/database/basic/ItemDatabase.php');

require_once($ROOT.'/objects/item/Item.php');
require_once($ROOT.'/objects/item/ItemType.php');

use item\Item;
use item\ItemType;

require_once($ROOT.'/objects/special/Buff.php');

use special\Attributes;
use special\Buff;



class DatabaseWorker
{
    public static function readDatabase(string $filename, AllDatabase &$database)
    {
        $xml = simplexml_load_file(realpath(dirname(__FILE__).'/../../data/'.$filename));

        foreach ($xml as $key => $value) {
            switch ($key) {
                case "ITEMS": $database->setItemDatabase(self::readItemDatabase($value)); break;
                case "CONSEQUENCES": $database->setConsequenceDatabase(self::readConsequencesDatabase($value)); break;
                case "CHARACTERS": $database->setCharacterDatabase(self::readCharacterDatabase($value)); break;
                case "EVENTS": $database->setActionDatabase(self::readEventsDatabase($value)); break;
                default: echo "ITEM IS NOT RECOGNISED"; break;
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

        return $consequences;
    }

    private static function readCharacterDatabase(?\SimpleXMLElement $value) : CharacterDatabase
    {
        $characters = new CharacterDatabase();

        foreach ($value->children() as $children => $character)
        {
            $characters->add(self::readCharacter($character));
        }

        return $characters;
    }

    private static function readEventsDatabase(?\SimpleXMLElement $value) : EventDatabase
    {
        $events = new EventDatabase();

        foreach ($value->children() as $children => $event)
        {
            $events->add(self::readEvent($event));
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

    private static function readCharacter(?\SimpleXMLElement $character) : Character
    {
        $characterAttributes = $character->attributes();

        $id = intval($characterAttributes['ID']);
        $name = $characterAttributes['Name'];
        $image = $characterAttributes['Image'];

        $buff = self::readBuff($character->Buff);
        return new Character($id, $name, $image, $buff);
    }

    private static function readAction(?\SimpleXMLElement $action) : \Action
    {
        $actionAttributes = $action->attributes();
        $type = intval($actionAttributes['Type']);
        $to = intval($actionAttributes['To']);
        $splitter = $actionAttributes['Splitter'];

        $data = strip_tags($action->Data);
        return new \Action($type, $data, $to, $splitter);
    }

    private static function readEvent(?\SimpleXMLElement $event) : Event
    {
        $eventAttributes = $event->attributes();

        $id = intval($eventAttributes['ID']);
        $name = intval($eventAttributes['Name']);
        $description = $eventAttributes['Description'];

        $actions = array();
        foreach ($event as $key => $action)
        {
            if($key !== "Action") {
                continue;
            }
            $actions[] = self::readAction($action);
        }
        return new Event($id, $name, $actions, $description);
    }
}