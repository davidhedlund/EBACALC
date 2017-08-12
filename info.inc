<?php
$body_water_in_blood="0.806";
$body_water=$tbw_kg/$bw_kg;
$ebac_per_ml_acohol=round(($body_water_in_blood*0.1)/($body_water*$bw_kg), 4);

$ebac_per_unit_of_alcohol=round(
($body_water_in_blood*1)/($body_water*$bw_kg)
, 3);

$ebac_per_us_standard_drink=round(
($body_water_in_blood*1.5)/($body_water*$bw_kg)
, 3);
?>
