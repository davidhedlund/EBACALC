<?php
echo "
<p><h2>Drinking scheme for $bw_kg kg body weight, $tbw_kg total body water</h2></p>

<table border=\"1\" width=\"800\">";

$alcohol__list = array(
array(
    'minutes' => 10,
    'beverage_name' => "Wine",
    'beverage_millilitre' => 175,
    'glass_comment' => "",
    'glass' => "",
    'beverage_alchol_by_volume' => 12,
    'beverage_sparkling' => "Yes",
    'description' => "Enter",
    'price' => "",
  ),
array(
    'minutes' => 60,
    'beverage_name' => "Wine",
    'beverage_millilitre' => 175,
    'glass_comment' => "",
    'glass' => "",
    'beverage_alchol_by_volume' => 12,
    'beverage_sparkling' => "Yes",
    'description' => "Adjust",
    'price' => "",
  ),
array(
    'minutes' => 120,
    'beverage_name' => "Wine",
    'beverage_millilitre' => 175,
    'glass_comment' => "",
    'glass' => "",
    'beverage_alchol_by_volume' => 12,
    'beverage_sparkling' => "Yes",
    'description' => "Maintain",
    'price' => "",
  ),
);
require "info.inc";
$enviroment="Pub";
require "table.inc";
require "calc.inc";


$alcohol__list = array(
array(
    'minutes' => 89,
    'beverage_name' => "Vodka",
    'beverage_millilitre' => 40,
    'glass_comment' => "",
    'glass' => "",
    'beverage_alchol_by_volume' => 40,
    'beverage_sparkling' => "No",
    'description' => "Adjust",
    'price' => "",
  ),
array(
    'minutes' => 0,
    'beverage_name' => "Vodka",
    'beverage_millilitre' => 80,
    'glass_comment' => "2 x 4 cL",
    'glass' => "",
    'beverage_alchol_by_volume' => 40,
    'beverage_sparkling' => "No",
    'description' => "Enter",
    'price' => "",
  ),
);
require "info.inc";
$enviroment="Pub";
require "table.inc";
require "calc.inc";

echo "</table>";
?>
