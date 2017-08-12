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



#if (isset($_GET['bw_kg'])) $bw_kg=$_GET['bw_kg']; else $bw_kg="70"; # Median weight for women. So if sex is switched from male to female, nothing has to be changed
#if (isset($_GET['tbw_kg'])) $tbw_kg=$_GET['tbw_kg'];
#if (isset($_GET['metabolism'])) $metabolism=$_GET['metabolism']; else $metabolism="0.012";




if (isset($_GET['limit'])) $maximal_ebac=$_GET['limit']; else $maximal_ebac=0.099; # 0.10 margin from drunked means that a 1/4 glass of 12% wine can be consumed every 44 minutes for a 70 kilo male with normal metabolism (0.015).
$alcohol_ml_not_dangerous=round (60/70*$bw_kg);
$alcohol_ml_low_risk=round (160/70*$bw_kg);
$alcohol_ml_intermediate_risk=300;
$alcohol_ml_high_risk=500;

if (isset($_GET['unit'])) $unit=$_GET['unit']; else $unit="";
if (isset($_GET['abv'])) $abv=$_GET['abv']; else $abv="";
if (isset($_GET['sparkling'])) $sparkling=$_GET['sparkling']; else $sparkling="";





#   exit;
if (isset($_GET['calculator_visibility'])) $calculator_visibility=$_GET['calculator_visibility']; else $calculator_visibility="show";





if (!isset($_GET['bw_kg'])) $empty_form__bw_kg=true;
if (!isset($_GET['tbw_kg'])) $empty_form__tbw_kg=true;
if (!isset($_GET['metabolism'])) $empty_form__metabolism=true;
if (!isset($_GET['limit'])) $empty_form__limit=true;

if (
    $empty_form__bw_kg == true ||
    $empty_form__tbw_kg == true ||
    $empty_form__metabolism == true ||
    $empty_form__limit == true
) {
$show_results=false;
}
else $show_results=true;





if (isset($_GET['bw_kg']) && empty($_GET['bw_kg'])) $incomplete_form__bw_kg=true;
if (isset($_GET['tbw_kg']) && empty($_GET['tbw_kg'])) $incomplete_form__tbw_kg=true;
if ($_GET['metabolism'] == "SELECT") $incomplete_form__metabolism=true;
if ($_GET['limit'] == "SELECT") $incomplete_form__limit=true;

if (
    $incomplete_form__bw_kg == true ||
    $incomplete_form__tbw_kg == true ||
    $incomplete_form__metabolism == true ||
    $incomplete_form__limit == true
) {
$calculator_visibility="show";
$show_results=false;
}


?>
<?php header("Content-type: text/html; charset=UTF-8"); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
  <head>
    <meta http-equiv="content-type" content="text/html; charset=UTF-8" />
    <meta name="keywords" content="EBACALC, Estimated Blood Alcohol Content Calculator" />
    <title>EBACALC</title>
  </head>

  <body style="margin:0">

<table style="width:80px" align="center">
  <tr>
    <td>


<?php
if ($calculator_visibility == "show") require "main.inc"; ?>

<p></p>

<?php
if ($show_results == true) {
    
    require "info.inc";
    require "pre-text.inc";
    
}
?>

<a href="About.html">About</a> this software.

<p><hr />Copyright &copy; 2017 David Hedlund. This work is licensed under GNU GPL version 3 or later.</p>

    </td>
  </tr>
</table>

  </body>
</html>
