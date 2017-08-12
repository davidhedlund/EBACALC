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

unset ($previous, $ebac, $ebac_previous, $ebac_metabolization, $minutes_total, $minutes_previous, $alcohol_ml, $alcohol_ml_total);
for ($i = 0; $i < count($alcohol__list); $i++){

# Eliminated alcohol
if ("{$alcohol__list[$i]['beverage_sparkling']}"=="Yes") $metabolism=$metabolism*1.385;


$ebac_metabolization="{$alcohol__list[$i]['minutes']}"*($metabolism/60);


$alcohol_ml="{$alcohol__list[$i]['beverage_millilitre']}"*"{$alcohol__list[$i]['beverage_alchol_by_volume']}"/1000*10;


$minutes_total=$minutes_total+"{$alcohol__list[$i]['minutes']}";
$alcohol_ml_total=$alcohol_ml_total+$alcohol_ml;


if ("{$alcohol__list[$i]['beverage_sparkling']}"=="Yes") $ebac=($ebac+$ebac_per_ml_acohol*$alcohol_ml*1.385)-$ebac_metabolization;
else $ebac=($ebac+$ebac_per_ml_acohol*$alcohol_ml)-$ebac_metabolization;

 if ($ebac<=0) $ebac=0;

if ($ebac<=0) 
  {

    if ("{$alcohol__list[$i]['beverage_sparkling']}"=="Yes") $ebac=($ebac+$ebac_per_ml_acohol*$alcohol_ml*1.385);
    else $ebac=($ebac+$ebac_per_ml_acohol*$alcohol_ml);

}


 if ($ebac<=0) { $ebac_color="black"; $ebac_definition=""; }
 elseif ($ebac<0.030) { $ebac_color="blue"; $ebac_definition="moderate"; }
 elseif ($ebac>=0.030 && $ebac<$maximal_ebac+0.001) { $ebac_color="green"; $ebac_definition="Salongs"; }
 elseif ($ebac>$maximal_ebac+0.001) { $ebac_color="red"; $ebac_definition="to high"; }

$previous=$ebac_previous-($metabolism/60*("{$alcohol__list[$i]['minutes']}"));
 if ($previous>=$maximal_ebac+0.001) $color_previous="red";

echo "
  <tr>
    <td>";

      $minutes = "{$alcohol__list[$i]['minutes']}";
      $h = floor (($minutes) / 60);
      $m = $minutes - ($h * 60);
      echo "{$h}:"; if ("{$m}"<=9) echo "0"; echo "{$m}";

      echo "</td>
    <td>+";

      $h = floor (($minutes_total) / 60);
      $m = $minutes_total - ($h * 60);
      echo "{$h}:"; if ("{$m}"<=9) echo "0"; echo "{$m}";

echo "</td>
    <td>";
 if ("{$alcohol__list[$i]['glass']}"!=="") echo "Glass {$alcohol__list[$i]['glass']}, ";
 echo "{$alcohol__list[$i]['beverage_name']}, {$alcohol__list[$i]['beverage_millilitre']} mL";
 if ("{$alcohol__list[$i]['glass_comment']}"!=="") echo " ({$alcohol__list[$i]['glass_comment']})";
echo ", {$alcohol__list[$i]['beverage_alchol_by_volume']}% <abbr title=\"alcohol by volume\">ABV</abbr>";
 if ("{$alcohol__list[$i]['beverage_sparkling']}"=="Yes") echo ", sparkling (38.5% faster metabolization)";
 echo ": $alcohol_ml mL alcohol</td>
    <td align=\"right\" style=\"color:";
echo $color_previous; echo "\";>";

 if ($previous>0) {
   echo round ($previous, 3);
 }
 else echo 0;
 echo "</td>
    <td align=\"left\" style=\"color:";
echo $color_previous; echo "\";>";

 if ($previous>0) {
   echo round ($previous*1000);
 }
 else echo 0;

echo "</td>
    <td align=\"right\" style=\"color: $ebac_color\";>";


echo round ($ebac, 3);

 echo "</td>
    <td align=\"left\" style=\"color: $ebac_color\">";
 
 echo round ($ebac*1000);
echo "</td>
    <td>{$alcohol__list[$i]['description']}</td>
    <td";

 if ($alcohol_ml_total<=$alcohol_ml_not_dangerous) echo " style=\"color: green\";>";
 elseif ($alcohol_ml_total<=$alcohol_ml_low_risk) echo " style=\"color: #c2c400\";>";
 elseif ($alcohol_ml_total<=$alcohol_ml_intermediate_risk) echo " style=\"color: #ffc000\";>";
 elseif ($alcohol_ml_total<=$alcohol_ml_high_risk) echo " style=\"color: #ff8400\";>";
 elseif ($alcohol_ml_total>$alcohol_ml_high_risk) echo " style=\"color: #cb2b00\";>";


 else echo " style=\"color: red\";>";
 echo round ($alcohol_ml_total, 1)."</td>
    <td>{$alcohol__list[$i]['price']}</td>
  </tr>
";


$minutes_previous="{$alcohol__list[$i]['minutes']}";
 if ($ebac<0) unset ($ebac_previous);
else $ebac_previous=$ebac;
 }
?>
