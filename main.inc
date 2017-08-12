<h2>EBACALC &#151; Estimated Blood Alcohol Content Calculator</h2>

<p>
<em style="color:purple">A tool to reduce the risk of binge drinking</em>
</p>


<form method="post" action="redirect.php" style="background-color: lightgray; padding: 10px;">

<h3>Physiological data</h3>

<p>
Body weight: <input type="text" name="bw_kg" value="<?php echo $_GET['bw_kg']; ?>" style="width:25px;" /> kg
<?php if ($incomplete_form__bw_kg == true) echo "<br /><span style=\"color:red\">This is required.</span>"; ?>

</p>

<p>
Total body water (TBW): <input type="text" name="tbw_kg" value="<?php echo $_GET['tbw_kg']; ?>" style="width:25px;" /> kg<br />

<?php if ($incomplete_form__tbw_kg == true) echo "<br /><span style=\"color:red\">This is required.</span>"; ?>


<p>
Use <a href="http://www.medindia.net/doctors/clinical_cal/bodywater.asp">Total Body Water calculator</a> (select Watson or Hume-Weyer formula to be sure) if you are not certain about your TBW.
</p>


Ethanol metabolism rate:
<select name="metabolism">
     <option value="SELECT" <?php if(!isset($bw_kg)) echo "selected=\"selected\""; ?>>Select</option>


<?php
$i = 10;
while ($i <= 40) {
  echo "  <option value=\"0.0$i\"";
  if ($_GET['metabolism'] == "0.0$i") echo " selected=\"selected\" ";
  echo ">0.0$i";
  if ($i=="12") echo " (average nondrinking males)"; elseif ($i=="15") echo " (moderate drinking males, or nondrinking women)"; elseif ($i=="17") echo " (moderate drinking females)";
  echo "</option>"; $i++;
}
?>
</select> (+/-4 mg)


<?php if ($incomplete_form__metabolism == true) echo "<br /><span style=\"color:red\">This is required.</span>"; ?>


<br /><br />

Blood alcohol content (BAC) limit:
<select name="limit">
           <option value="SELECT" <?php if(!isset($_GET['limit'])) echo "selected=\"selected\""; ?>>Select</option>

<?php
$max_limit=600;

$i = 1;
while ($i <= $max_limit) {
if ($i>=1 && $i<10) $i="00$i";
elseif ($i<=99 && $i<100) $i="0$i";
elseif ($i<=999) $i="$i";

echo "  <option value=\"0.$i\"";

  if ($_GET['limit'] == "0.$i") echo " selected=\"selected\" ";

echo ">0.$i";

if ($i>="80") echo " - Binge drinking (NIAAAA definition)";


#if ($i>=1 && $i<=29) echo " - Average individual appears normal";
#  elseif ($i>=30 && $i<=59) echo " - Decreased inhibition";
#  elseif ($i>=60 && $i<=99) echo " - Disinhibition";
#  elseif ($i>=100 && $i<=199) echo " - Possibility of nausea and vomiting";
#  elseif ($i>=200 && $i<=299) echo " - Nausea, vomiting";
#  elseif ($i>=300 && $i<=399) echo " - Low possibility of death";
#  elseif ($i>=400 && $i<=499) echo " - Possibility of death";
#  elseif ($i>=500 && $i<=600) echo " - High possibility of death";

echo "</option>\n"; $i++;
}
?>
</select>

<?php if ($incomplete_form__limit == true) echo "<br /><span style=\"color:red\">This is required.</span>"; ?>

<br /><br />

<hr />

<h3>Alcoholic beverage</h3>
This data will be represent in the "Custom" columns when you submit it.


<p>
Unit: <input type="text" name="unit" value="<?php echo $unit; ?>" style="width:30px;" /> mL<br /><br />
Alcohol by volume (ABV): <input type="text" name="abv" value="<?php echo $abv; ?>" style="width:20px;" /> %<br /><br />

</select>

Sparkling:
<input type="radio" name="sparkling" value="Non-sparkling" <?php if ($sparkling=="Non-sparkling") echo " checked=\"checked\""; ?> /> Non-sparkling
<input type="radio" name="sparkling" value="Sparkling" <?php if ($sparkling=="Sparkling") echo " checked=\"checked\""; ?> /> Sparkling<br /><br />

<hr />

Calculator visibility:<br />
<input type="radio" name="calculator_visibility" value="show" <?php if ($calculator_visibility=="Show" || empty($_GET['abv'])
) echo " checked=\"checked\""; ?> /> Show: Useful to edit current output<br />
    <input type="radio" name="calculator_visibility" value="hide" <?php if ($calculator_visibility=="Hide") echo " checked=\"checked\""; ?> /> Hide: Useful to save the data output to a clean page<br /><br />

<p>


<input type="submit" value="Calculate Estimated Blood Alcohol Content" />

</form>
