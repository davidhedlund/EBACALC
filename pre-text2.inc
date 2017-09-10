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

# Define variables
$millilitre_alcohol="{$alcohol__list[$i]['millilitre']}" * "{$alcohol__list[$i]['alcohol_volume']}"/1000*10;

if ("{$alcohol__list[$i]['drinking_minutes']}" >= 1) $ebac=$ebac_per_ml_acohol * $millilitre_alcohol - $metabolism*"{$alcohol__list[$i]['drinking_minutes']}"/100;
else $ebac=$ebac_per_ml_acohol * $millilitre_alcohol;


$ebac_metabolized_in_minutes=($ebac/$metabolism)*60;


if ("{$alcohol__list[$i]['beverage_sparkling']}"=="Yes") {
   $ebac=round($ebac*1.385, 3);
   $ebac_metabolized_in_minutes=$ebac_metabolized_in_minutes*0.615;
}

if ("{$alcohol__list[$i]['repeat']}"=="y") $minutes=round($ebac_metabolized_in_minutes+$previous__ebac_metabolized_in_minutes);
else $minutes = round($ebac_metabolized_in_minutes);

$h = floor (($minutes) / 60);
$m = $minutes - ($h * 60);

 $$alcohol__list[$i]['name']=round($ebac_metabolized_in_minutes);

if ("{$alcohol__list[$i]['repeat']}"=="y") $max_ebac=$ebac+$previous__ebac;
else $max_ebac=$ebac;


if ("{$alcohol__list[$i]['repeat']}"=="y") $total__ebac_metabolized_in_minutes=$ebac_metabolized_in_minutes+$previous__ebac_metabolized_in_minutes;
else $total__ebac_metabolized_in_minutes=$ebac_metabolized_in_minutes;



# Begin application

  if ($max_ebac<$maximal_ebac) {




    echo "<tr ";

 if ($i!==$previous__i) $counter++; if (is_float($counter/2)) $class = "white"; else $class = "lightgrey";

echo " style=\"background-color: $class\"";

echo ">";

    echo "\n    <td>";

 
echo "{$alcohol__list[$i]['alcohol_volume']}%";

echo " {$alcohol__list[$i]['name']}";

echo "</td>";


echo "<td>";
if ("{$alcohol__list[$i]['beverage_sparkling']}"=="Yes") echo "Sparkling"; else echo "Still";
echo "</td>";



echo "<td>";
if ("{$alcohol__list[$i]['repeat']}"=="y") echo "{$alcohol__list[$i]['millilitre']}"+$previous__millilitre; else echo "{$alcohol__list[$i]['millilitre']}";
echo  " mL";


if ("{$alcohol__list[$i]['name']}"=="Wine") {

echo ": ";

if ("{$alcohol__list[$i]['repeat']}"=="y") echo round(("{$alcohol__list[$i]['millilitre']}"+$previous__millilitre)/150, 2); else echo round ("{$alcohol__list[$i]['millilitre']}"/150, 2);

echo " wine glass";

}

if ("{$alcohol__list[$i]['name']}"=="Champagne") {

echo ": ";

if ("{$alcohol__list[$i]['repeat']}"=="y") echo round(("{$alcohol__list[$i]['millilitre']}"+$previous__millilitre)/150, 2); else echo round ("{$alcohol__list[$i]['millilitre']}"/150, 2);

echo " champagne glass";

}


echo "</td>";





echo "\n<td>";

if ("{$alcohol__list[$i]['repeat']}"=="y") echo $millilitre_alcohol+$previous__millilitre_alcohol; # Ethanol weight per ml
else echo $millilitre_alcohol;

 echo " mL";

 echo "</td>";









echo "\n<td>";

 if ("{$alcohol__list[$i]['repeat']}"=="y") echo round(($millilitre_alcohol+$previous__millilitre_alcohol)*0.789, 1); # Ethanol weight per ml
else echo round ($millilitre_alcohol*0.789, 1);
echo " g";






 echo "</td>\n";






echo "<td>";

 if ("{$alcohol__list[$i]['repeat']}"=="y") {
   echo round ($ebac+$previous__ebac, 3);
   if (strlen(round ($previous__ebac+$ebac, 3))=="4") echo "0"; # Lägg till 0 för avrundade tal så att de kan användas för huvudräkning. 0.02040 avrundas till 0.02 vilket gör att "2" istället för "20" av misstag kan råka användas som referens för att räkna ut väntetid mellan "1/4th drink dose/metabolized in".
  }
 else {
   echo round ($ebac, 3);
   if (strlen(round ($ebac, 3))=="4") echo "0"; # Lägg till 0 för avrundade tal så att de kan användas för huvudräkning. 0.02040 avrundas till 0.02 vilket gör att "2" istället för "20" av misstag kan råka användas som referens för att räkna ut väntetid mellan "1/4th drink dose/metabolized in".
  }

echo "%";


 echo " / {$h}:"; if ("{$m}"<=9) echo "0"; echo "{$m}";


 if ($total__ebac_metabolized_in_minutes >= 60) {

 echo "<!-- ";





echo round ($total__ebac_metabolized_in_minutes);

echo " min-->";

 }


echo "</td>";

echo "<td>";



if ($total__ebac_metabolized_in_minutes >= 60 && $hour <= "1" && $hour !== "1") { echo "1 hour"; $hour="1"; }
if ($total__ebac_metabolized_in_minutes >= 120 && $hour <= "2" && $hour !== "2") { echo "2 hours"; $hour="2"; }
if ($total__ebac_metabolized_in_minutes >= 180 && $hour <= "3" && $hour !== "3") { echo "3 hours"; $hour="3"; }
if ($total__ebac_metabolized_in_minutes >= 240 && $hour <= "4" && $hour !== "4") { echo "4 hours"; $hour="4"; }
if ($total__ebac_metabolized_in_minutes >= 300 && $hour <= "5" && $hour !== "5") { echo "5 hours"; $hour="5"; }




echo "</td>";


 
 echo "\n</tr>";

$previous__ebac_metabolized_in_minutes=$previous__ebac_metabolized_in_minutes+$ebac_metabolized_in_minutes;
$previous__ebac=$previous__ebac+$ebac;
$previous__millilitre=$previous__millilitre+"{$alcohol__list[$i]['millilitre']}";
$previous__millilitre_alcohol=$millilitre_alcohol+$previous__millilitre_alcohol;
$previous__i=$i;

}
?>
