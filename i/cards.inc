<?php
$card_list = '[
		{
			"id" : 1,
			"name" : "Mountain",
			"suit" : "Land",
			"base" : 9,
			"desc_eng" : "BONUS: +50 with both Smoke and Wildfire.\nClears the Penalty on all Floods.",
			"desc_kor" : "보너스: Smoke 와 Wildfire 둘 다 있으면 +50점.\n모든 Flood에 대한 패널티를 없앤다.",
			"bonus" : {
				"point" : 50,
				"type" : "withall",
				"list" : [
					{
						"type" : "card",
						"id" : 13
					},
					{
						"type" : "card",
						"id" : 16
					}
				]
			},
			"clear" : {
				"type" : "all",
				"list" : [
					{
						"type" : "suit",
						"id" : "Flood"
					}
				]
			}
		},
		{
			"id" : 2,
			"name" : "Cavern",
			"suit" : "Land",
			"base" : 6,
			"desc_eng" : "BONUS: +25 with Dwarvish Infantry or Dragon.\nCLEARS the Penalty on all Weather.",
			"desc_kor" : "보너스: Dwarvish Infantry 나 Dragon 이 있으면 +25점.\n모든 Weather에 대한 패널티를 없앤다.",
			"bonus" : {
				"point" : 25,
				"type" : "withor",
				"list" : [
					{
						"type" : "card",
						"id" : 24
					},
					{
						"type" : "card",
						"id" : 39
					}
				]
			},
			"clear" : {
				"type" : "all",
				"list" : [
					{
						"type" : "suit",
						"id" : "Weather"
					}
				]
			}
		},
		{
			"id" : 3,
			"name" : "Bell Tower",
			"suit" : "Land",
			"base" : 8,
			"desc_eng" : "+15 with any one Wizard",
			"desc_kor" : "Wizard가 있으면 +15점",
			"bonus" : {
				"point" : 15,
				"type" : "withany",
				"list" : [
					{
						"type" : "suit",
						"id" : "Wizard"
					}
				]
			}
		},
		{
			"id" : 4,
			"name" : "Forest",
			"suit" : "Land",
			"base" : 7,
			"desc_eng" : "+12 for each Beast and Elven Archers",
			"desc_kor" : "Beast와 Elven Archers 마다 +12점",
			"bonus" : {
				"point" : 12,
				"type" : "foreach",
				"list" : [
					{
						"type" : "suit",
						"id" : "Beast"
					},
					{
						"type" : "card",
						"id" : 22
					}
				]
			}
		},
		{
			"id" : 5,
			"name" : "Earth Elemental",
			"suit" : "Land",
			"base" : 4,
			"desc_eng" : "+15 for each other Land",
			"desc_kor" : "다른 Land마다 +15점",
			"bonus" : {
				"point" : 15,
				"type" : "foreachother",
				"list" : [
					{
						"type" : "suit",
						"id" : "Land"
					}
				]
			}
		},
		{
			"id" : 6,
			"name" : "Fountain of Life",
			"suit" : "Flood",
			"base" : 1,
			"bonus" : "Add the base strengh of any one Weapon, Flood, Flame, Land or Weather"
		},
		{
			"id" : 7,
			"name" : "Swamp",
			"suit" : "Flood",
			"base" : 18,
			"penalty" : "-3 for each Army and Flame"
		},
		{
			"id" : 8,
			"name" : "Great Flood",
			"suit" : "Flood",
			"base" : 32,
			"penalty" : "blanks all Armies, all lands except Mountain, and all Flame except Lighting"
		},
		{
			"id" : 9,
			"name" : "Island",
			"suit" : "Flood",
			"base" : 14,
			"clear" : "penalty on any one Flood or Flame"
		},
		{
			"id" : 10,
			"name" : "Water Elemental",
			"suit" : "Flood",
			"base" : 4,
			"penalty" : "+15 for each other Flood"
		},
		{
			"id" : 13,
			"name" : "Smoke",
			"suit" : "Weather",
			"base" : 27,
			"penalty_desc_eng" : "This card is BLANKED unless with at least one Flame"
		},
		{
			"id" : 16,
			"name" : "Wildfire",
			"suit" : "Flame",
			"base" : 40,
			"desc_eng" : "BLANKS all cards except Flames, Wizards, Weather, Weapons, Artifacts, Mountain, Great Flood, Island, Unicorn and Dragon"
		},
		{
			"id" : 22,
			"name" : "Elven Archers",
			"suit" : "Army",
			"base" : 10,
			"desc_eng" : "BONUS: +5 if no Weather."
		},
		{
			"id" : 24,
			"name" : "Dwarvish Infantry",
			"suit" : "Army",
			"base" : 15,
			"desc_eng" : "PENALTY: -2 for each other Army."
		},
		{
			"id" : 27,
			"name" : "Beast Master",
			"suit" : "Wizard",
			"base" : 9,
			"desc_eng" : "BONUS: +9 for each Beast. CLEARS the Penalty on all Beasts."
		},
		{
			"id" : 39,
			"name" : "Dragon",
			"suit" : "Beast",
			"base" : 30,
			"desc_eng" : "PENALTY: -40 unless with at least one Wizard."
		}
]';
$gRealmCards = json_decode($card_list);
?>
