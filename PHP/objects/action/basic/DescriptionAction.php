<?php

require_once ("Action.php");

class DescriptionAction extends Action
{
    private $textData;
    private $imageName;
    private $music;

    public function __construct($actionType, $data, $toActionId, $splitter)
    {
        parent::__construct($actionType, $data, $toActionId, $splitter);
        // TODO: GET ALL DATA FROM ACTION
    }

    /**
     * @return mixed
     */
    public function getTextData()
    {
        return $this->textData;
    }

    /**
     * @param mixed $textData
     */
    public function setTextData($textData): void
    {
        $this->textData = $textData;
    }

    /**
     * @return mixed
     */
    public function getImageName()
    {
        return $this->imageName;
    }

    /**
     * @param mixed $imageName
     */
    public function setImageName($imageName): void
    {
        $this->imageName = $imageName;
    }

    /**
     * @return mixed
     */
    public function getMusic()
    {
        return $this->music;
    }

    /**
     * @param mixed $music
     */
    public function setMusic($music): void
    {
        $this->music = $music;
    }


}