<?php

require_once("../i/cards.inc");

print("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"><br>\n");
//print($card_list);
$cards = json_decode($card_list);
print("<pre>");
foreach($cards as $card) print_r($card);
print("</pre>");
?>
