<?php
# EBACALC — Estimated Blood Alcohol Content Calculator
#
# Copyright (C) 2017 David Hedlund
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

echo "
<p><hr /></p>
<h2>Submitted information</h2>
Body weight: $bw_kg kg<br />
Total body water (TBW): $tbw_kg<br />
Metabolization per hour: $metabolism%<br />
Estimated blood alcohol content:<br />
&nbsp;&nbsp;&nbsp;&nbsp;EBAC per mL of alchohol: $ebac_per_ml_acohol%<br />
&nbsp;&nbsp;&nbsp;&nbsp;EBAC per unit of alcohol (10 mL alcohol): $ebac_per_unit_of_alcohol%<br />
&nbsp;&nbsp;&nbsp;&nbsp;EBAC per US standard drink (15 mL alcohol): $ebac_per_us_standard_drink%<br />

<p>
These calculations are based on \"normal fully stomach content\". People who do not eat before drinking can have a BAC three times higher than those who do.
</p>

<p><h2>Alcohol equivalence based on submitted information:</h2></p>

<table border=\"1\" width=\"800\">
";








$alcohol__list = array(
array(
    'name' => "Custom",
    'millilitre' => "$unit",
    'alcohol_volume' => "$abv",
    'common_unit' => "n",
    'repeat' => "y",
    'beverage_sparkling' => "$sparkling",
  ),
array(
    'name' => "Wine",
    'millilitre' => "150",
    'alcohol_volume' => "8",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "No",
    'common_unit' => "y",
    'repeat' => "y",
  ),
array(
    'name' => "Wine",
    'millilitre' => "150",
    'alcohol_volume' => "9",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "No",
    'common_unit' => "y",
    'repeat' => "y",
  ),
array(
    'name' => "Wine",
    'millilitre' => "150",
    'alcohol_volume' => "10",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "No",
    'common_unit' => "y",
    'repeat' => "y",
  ),
array(
    'name' => "Wine",
    'millilitre' => "150",
    'alcohol_volume' => "11",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "No",
    'common_unit' => "y",
    'repeat' => "y",
  ),
array(
    'name' => "Wine",
    'millilitre' => "150",
    'alcohol_volume' => "12",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "No",
    'common_unit' => "y",
    'repeat' => "y",
  ),
array(
    'name' => "Wine",
    'millilitre' => "150",
    'alcohol_volume' => "13",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "No",
    'common_unit' => "y",
    'repeat' => "y",
  ),
array(
    'name' => "Wine",
    'millilitre' => "150",
    'alcohol_volume' => "14",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "No",
    'common_unit' => "y",
    'repeat' => "y",
  ),
array(
    'name' => "Fortified wine",
    'millilitre' => "150",
    'alcohol_volume' => "15",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "No",
    'common_unit' => "y",
    'repeat' => "y",
  ),
  array(
    'name' => "Fortified wine",
    'millilitre' => "150",
    'alcohol_volume' => "16",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "No",
    'common_unit' => "y",
    'repeat' => "y",
  ),
  array(
    'name' => "Fortified wine",
    'millilitre' => "150",
    'alcohol_volume' => "17",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "No",
    'common_unit' => "y",
    'repeat' => "y",
  ),
  array(
    'name' => "Fortified wine",
    'millilitre' => "150",
    'alcohol_volume' => "18",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "No",
    'common_unit' => "y",
    'repeat' => "y",
  ),
  array(
    'name' => "Fortified wine",
    'millilitre' => "150",
    'alcohol_volume' => "19",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "No",
    'common_unit' => "y",
    'repeat' => "y",
  ),
  array(
    'name' => "Fortified wine",
    'millilitre' => "150",
    'alcohol_volume' => "20",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "No",
    'common_unit' => "y",
    'repeat' => "y",
  ),
  array(
    'name' => "Fortified wine",
    'millilitre' => "150",
    'alcohol_volume' => "21",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "No",
    'common_unit' => "y",
    'repeat' => "y",
  ),
  array(
    'name' => "Fortified wine",
    'millilitre' => "150",
    'alcohol_volume' => "22",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "No",
    'common_unit' => "y",
    'repeat' => "y",
  ),
array(
    'name' => "Champagne",
    'millilitre' => "150",
    'alcohol_volume' => "8",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "Yes",
    'common_unit' => "y",
    'repeat' => "y",
  ),
array(
    'name' => "Champagne",
    'millilitre' => "150",
    'alcohol_volume' => "9",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "Yes",
    'common_unit' => "y",
    'repeat' => "y",
  ),
array(
    'name' => "Champagne",
    'millilitre' => "150",
    'alcohol_volume' => "10",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "Yes",
    'common_unit' => "y",
    'repeat' => "y",
  ),
array(
    'name' => "Champagne",
    'millilitre' => "150",
    'alcohol_volume' => "11",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "Yes",
    'common_unit' => "y",
    'repeat' => "y",
  ),
array(
    'name' => "Champagne",
    'millilitre' => "150",
    'alcohol_volume' => "12",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "Yes",
    'common_unit' => "y",
    'repeat' => "y",
  ),
array(
    'name' => "Champagne",
    'millilitre' => "150",
    'alcohol_volume' => "13",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "Yes",
    'common_unit' => "y",
    'repeat' => "y",
  ),
array(
    'name' => "Champagne",
    'millilitre' => "150",
    'alcohol_volume' => "14",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "Yes",
    'common_unit' => "y",
    'repeat' => "y",
  ),
array(
    'name' => "Beer",
    'millilitre' => "500",
    'alcohol_volume' => "2.8",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "Yes",
    'repeat' => "y",
  ),
array(
    'name' => "Beer",
    'millilitre' => "500",
    'alcohol_volume' => "3.5",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "Yes",
    'repeat' => "y",
  ),
array(
    'name' => "Draught beer, British pint",
    'millilitre' => "568",
    'alcohol_volume' => "4.5",
    'drinking_minutes' => 60,
    'common_unit' => "y",
    'beverage_sparkling' => "No",
    'repeat' => "y",
  ),
array(
    'name' => "Draught beer, American pint",
    'millilitre' => "473",
    'alcohol_volume' => "4.5",
    'drinking_minutes' => 60,
    'common_unit' => "y",
    'beverage_sparkling' => "No",
    'repeat' => "y",
  ),
array(
    'name' => "Beer",
    'millilitre' => "500",
    'alcohol_volume' => "5",
    'drinking_minutes' => 60,
    'beverage_sparkling' => "Yes",
    'repeat' => "y",
  ),
array(
    'name' => "Beer",
    'millilitre' => "500",
    'alcohol_volume' => "7",
    'drinking_minutes' => 60,
    'repeat' => "y",
    'beverage_sparkling' => "Yes",
  ),
array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "10",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "15",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "20",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
  array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "25",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "30",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
  array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "35",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "40",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
array(
    'name' => "Spirit",
    'millilitre' => "50",
    'alcohol_volume' => "40",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
  array(
    'name' => "Spirit",
    'millilitre' => "43",
    'alcohol_volume' => "40",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
  array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "45",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "50",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "55",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
  array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "60",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
  array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "65",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "70",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
  array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "75",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
  array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "80",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
  array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "85",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "90",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
array(
    'name' => "Spirit",
    'millilitre' => "40",
    'alcohol_volume' => "96",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
  array(
    'name' => "Spirit",
    'millilitre' => "60",
    'alcohol_volume' => "40",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
array(
    'name' => "Spirit",
    'millilitre' => "10",
    'alcohol_volume' => "96",
    'drinking_minutes' => 0,
    'beverage_sparkling' => "No",
    'common_unit' => "n",
    'repeat' => "y",
  ),
);
?>

  <tr style="font-weight:bold; background-color: black; color: white;">
    <td>Alcohol by volume (<abbr title="alcohol by volume">ABV</abbr>)</td>
    <td>Still or sparkling</td>
    <td>Volume</td>
    <td>Drinking time</td>
    <td>Alcohol mL</td>
    <td>Alcohol g</td>
    <td>EBAC %, metabolization</td>
    <td>Lasts ~2 h</td>
  </tr>


  <?php
  for ($i = 0; $i < count($alcohol__list); $i++){

      if ($i=="0") echo "<tr><td colspan=\"3\" style=\"font-size:16pt; font-weight:bold\">Standard drinks</td></tr>";


      if ("{$alcohol__list[$i]['name']}" == "Custom" && !empty($unit) || "{$alcohol__list[$i]['name']}" !== "Custom") {



          echo "\n  <tr>";


          if ("{$alcohol__list[$i]['repeat']}"=="y") for ($ix = 0; $ix < 100; $ix++) require "pre-text2.inc";

          unset($previous__ebac_metabolized_in_minutes, 
                $previous__ebac, 
                $previous__millilitre, 
                $previous__millilitre_alcohol);

      }

  }
  ?>

</table>
