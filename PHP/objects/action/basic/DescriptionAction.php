<?php

require_once ("Action.php");

class DescriptionAction extends Action
{
    private string $textData;
    private string $imageName;
    private string $music;

    public function __construct($actionType, $data, $toActionId, $splitter)
    {
        parent::__construct($actionType, $data, $toActionId, $splitter);

        $neededData = explode($splitter, $data);

        $this->textData = $neededData[1];
        $this->imageName = $neededData[2];
        $this->music = $neededData[3];
    }

    public static function fromAction(Action $action) : DescriptionAction
    {
        return new DescriptionAction($action->getActionType(), $action->getData(), $action->getToActionId(), $action->getSplitter());
    }



    /**
     * @return string
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
     * @return string
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
     * @return string
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