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

$calculator_visibility = $_POST['calculator_visibility'];
$sex = $_POST['sex'];
$bw_kg = $_POST['bw_kg'];
$tbw_kg = $_POST['tbw_kg'];
$metabolism = $_POST['metabolism'];
$limit = $_POST['limit'];

$unit=$_POST['unit'];
$abv=$_POST['abv'];
$sparkling=$_POST['sparkling'];

header( "Location: .?bw_kg=$bw_kg&tbw_kg=$tbw_kg&metabolism=$metabolism&limit=$limit&unit=$unit&abv=$abv&sparkling=$sparkling&calculator_visibility=$calculator_visibility#Result" );
?>
