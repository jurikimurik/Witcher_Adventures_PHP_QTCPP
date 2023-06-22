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
    public function getTextData(): string
    {
        return $this->textData;
    }

    /**
     * @param string $textData
     */
    public function setTextData(string $textData): void
    {
        $this->textData = $textData;
    }

    /**
     * @return string
     */
    public function getImageName(): string
    {
        return $this->imageName;
    }

    /**
     * @param string $imageName
     */
    public function setImageName(string $imageName): void
    {
        $this->imageName = $imageName;
    }

    /**
     * @return string
     */
    public function getMusic(): string
    {
        return $this->music;
    }

    /**
     * @param string $music
     */
    public function setMusic(string $music): void
    {
        $this->music = $music;
    }


}