<?php

function getDice ($value = -1) {
    if($value === -1)
    {
    $value = rand(1, 6);
    }

    return <<<HTML
        <html lang="en">
        <fieldset style="display: inline-block">
        $value
</fieldset>
        </html>
HTML;
}
