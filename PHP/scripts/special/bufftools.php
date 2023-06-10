<?php

require_once (realpath(dirname(__FILE__).'/../../objects/special/Buff.php'));

use special\Buff;

function getBuffStatistics(Buff $buff, bool $hideZero = true) : array
{

    $attributes = $buff->getAttributes()->getValues();

    $statisticsText = Buff::getStatisticsText();

    if($buff->getDuration() <= -1) {
        $descriptions[0] = $statisticsText[0] . "Zawsze";
    } else {
        $descriptions[0] = $statisticsText[0].$buff->getDuration();
    }
    for($i = 1; $i < count(Buff::getStatisticsText()); $i++)
    {
        if($hideZero && $attributes[$i-1] === 0)  {
            continue;
        } else {
            $descriptions[$i] = $statisticsText[$i] . $attributes[$i - 1];
        }
    }

    return array_filter($descriptions);
}

function getBuffStatisticsBlock(Buff $buff, $hideZero = true) : string
{
    $descInStr = '<fieldset style="display: inline-block"> <table>';
    foreach (getBuffStatistics($buff, $hideZero) as $value)
    {
        $descInStr = $descInStr . '<tr><td>'.$value.'</td></tr>';
    }
    return $descInStr . '</table></fieldset>';
}