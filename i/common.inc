<?php

require_once("../i/cards.inc");

//$gRealmCards = json_decode($card_list);
function FindRealmCard($id)
{
//print("$id<br>");
	GLOBAL $gRealmCards;

//print("<pre>\n");
	foreach ($gRealmCards as $card) {
//print_r($card);
		if ($card->id==$id) return $card;
	}
//print("</pre>\n");
	return null;
}

function MakeScoreSheet($hands)
{
	$sheet = array();
	foreach ($hands as $hand) {
		$card = FindRealmCard($hand);
		$temp_list = array(
			'card_idx' => $hand,
			'base' => 0,
			'bonus' => 0,
			'penalty' => 0,
			'total' => 0,
		);
		if ($card==null) {
		}
		else {
			$temp_list['base'] = $card->base;
		}
		array_push($sheet, $temp_list);
	}
	return $sheet;
}

function CalcHands($hands)
{
	$score_sheet = MakeScoreSheet($hands);
/*
print("<pre>\n");
print_r($score_sheet);
print("</pre>\n");
 */
	return 0;
}
?>

