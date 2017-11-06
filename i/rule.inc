<?php

require_once("../i/cards.inc");

function FindRealmCard($id)
{
//print("$id<br>");
	GLOBAL $gRealmCards;

	foreach ($gRealmCards as $card) if ($card->id==$id) return $card;
	return null;
}

function MakeScoreSheet($hands)
{
	$sheet = array();
	foreach ($hands as $hand) {
		$temp_list = array(
			'card' => FindRealmCard($hand),
			'base' => 0,
			'bonus' => 0,
			'penalty' => 0,
			'penalty_cleared' => false,
			'total' => 0,
		);
		array_push($sheet, $temp_list);
	}
	return $sheet;
}

function IsTarget($card, $list)
{
	foreach ($list as $item) {
		if ($item->type=='suit') {
//print("<pre>\n"); print_r($card['card']->suit); print("</pre>\n");
//print "[$card->suit : $item->id]";
			if ($item->id==$card['card']->suit) return true;
			else continue;
		}
	}
	return false;
}

function CheckClearPenaltyCard($card, $clear)
{
	switch ($clear->type) {
		case 'all':
			if (IsTarget($card, $clear->list)) return true;
			else return false;
			break;
	}
}

function CheckClearPenaltySheet($sheet)
{
	foreach ($sheet as $card_score) {
		if (isset($card_score['card']->clear)) {
			foreach ($sheet as &$other_card) {
				if ($other_card['card']->id==$card_score['card']->id) continue;
				if (CheckClearPenaltyCard($other_card, $card_score['card']->clear)) $other_card['penalty_cleared'] = true;
			}
		}
	}
}

function HaveTarget($sheet, $target)
{
	if ($target->type=='card') {
		foreach ($sheet as $card) {
			if ($card['card']->id==$target->id) return true;
		}
	}
	else if ($target->type=='suit') {
		foreach ($sheet as $card) {
			if ($card['card']->suit==$target->id) return true;
		}
	}
	return false;
}

function CheckCardBonus($card, $sheet)
{
	switch ($card->bonus->type) {
		case 'withall':
			foreach ($card->bonus->list as $target) {
				if (!HaveTarget($sheet, $target)) return false;
			}
			return true;
		case 'withor':
		case 'withany':
			foreach ($card->bonus->list as $target) {
				if (HaveTarget($sheet, $target)) return true;
			}
			return false;
	}
	return false;
}

function CalcBonusSheet($sheet)
{
	foreach ($sheet as &$card_score) {
		if (isset($card_score['card']->bonus)) {
			if (CheckCardBonus($card_score['card'], $sheet)) $card_score['bonus'] = $card_score['card']->bonus->point;
		}
	}
}

function CalcHands($hands)
{
	// init score sheet
	$score_sheet = MakeScoreSheet($hands);

	// calculation
	// check clear
	CheckClearPenaltySheet(&$score_sheet);
	// calc bonus
	CalcBonusSheet(&$score_sheet);
	// calc penalty
//	CalcPenaltySheet(&$score_sheet);
	// total
//	$total = TotalScoreSheet(&$score_sheet);
print("<pre>\n");
print_r($score_sheet);
print("</pre>\n");
/*
 */
	return 0;
}
?>

